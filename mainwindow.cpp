#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QMessageBox>

#include <iostream>
#include <cstdio>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


Mat static markerMask, img0, img, imgGray, result;
Point static prevPt(-1, -1);
int static c;
QString static fileName;


static void onMouse( int event, int x, int y, int flags, void* )
{
    if( x < 0 || x >= img.cols || y < 0 || y >= img.rows )
        return;
    if( event == CV_EVENT_LBUTTONUP || !(flags & CV_EVENT_FLAG_LBUTTON) )
        prevPt = Point(-1,-1);
    else if( event == CV_EVENT_LBUTTONDOWN )
        prevPt = Point(x,y);
    else if( event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON) )
    {
        Point pt(x, y);
        if( prevPt.x < 0 )
            prevPt = pt;
        line( markerMask, prevPt, pt, Scalar::all(255), 5, 8, 0 );
        line( img, prevPt, pt, Scalar::all(255), 5, 8, 0 );
        prevPt = pt;
        imshow("image", img);
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::connect(ui->exitPushButton,SIGNAL(clicked()), qApp,SLOT(quit()));
    c = waitKey(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadPushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, ("Open File"),QDir::homePath(),("Images (*.png *.jpeg *.jpg)"));
    if(!fileName.isNull()) {
        img0 = imread(fileName.toStdString(), 1);
        if( img0.empty() )
        {
            QMessageBox::information(this, tr("Couldn'g open image"),tr("Sorry !"));
        }
        namedWindow( "image", WINDOW_AUTOSIZE );
        img0.copyTo(img);
        cvtColor(img, markerMask, COLOR_BGR2GRAY);
        cvtColor(markerMask, imgGray, COLOR_GRAY2BGR);
        markerMask = Scalar::all(0);
        imshow( "image", img );
        setMouseCallback( "image", onMouse, 0 );

        ui->resetPushButton->setEnabled(true);
        ui->doPushButton->setEnabled(true);
    } else {
        QMessageBox::information(this, tr("Unable to save file"), tr("Sorry !"));
    }
}

void MainWindow::on_resetPushButton_clicked()
{
    ui->savePushButton->setEnabled(false);
    ui->loadPushButton->setEnabled(true);

    destroyWindow("watershed transform");
    result.release();

    markerMask = Scalar::all(0);
    img0.copyTo(img);
    imshow( "image", img );

    ui->doPushButton->setEnabled(true);
}

void MainWindow::on_doPushButton_clicked()
{
    ui->savePushButton->setEnabled(false);
    ui->loadPushButton->setEnabled(false);

    if( c == 27 ) {ui->exitPushButton->click();}

    int i, j, compCount = 0;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(markerMask, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if( contours.empty() ){}

    Mat markers(markerMask.size(), CV_32S);
    markers = Scalar::all(0);
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0], compCount++ )
        drawContours(markers, contours, idx, Scalar::all(compCount+1), -1, 8, hierarchy, INT_MAX);

    if( compCount == 0 ){}

    vector<Vec3b> colorTab;
    for( i = 0; i < compCount; i++ )
    {
        int b = theRNG().uniform(0, 255);
        int g = theRNG().uniform(0, 255);
        int r = theRNG().uniform(0, 255);

        colorTab.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
    }

    double t = (double)getTickCount();
    watershed( img0, markers );
    t = (double)getTickCount() - t;
    printf( "execution time = %gms\n", t*1000./getTickFrequency() );

    Mat wshed(markers.size(), CV_8UC3);

    // paint the watershed image
    for( i = 0; i < markers.rows; i++ )
        for( j = 0; j < markers.cols; j++ )
        {
            int index = markers.at<int>(i,j);
            if( index == -1 )
                wshed.at<Vec3b>(i,j) = Vec3b(255,255,255);
            else if( index <= 0 || index > compCount )
                wshed.at<Vec3b>(i,j) = Vec3b(0,0,0);
            else
                wshed.at<Vec3b>(i,j) = colorTab[index - 1];
        }

    wshed = wshed*0.5 + imgGray*0.5;
    wshed.copyTo(result);

    QMessageBox::information(this, tr("The process has been done"), tr("Show the result"));
    imshow( "watershed transform", wshed );
    ui->savePushButton->setEnabled(true);
}

void MainWindow::on_savePushButton_clicked()
{
    if(!result.empty()) {
        QString s = QFileDialog::getSaveFileName( this,tr("Save Image"),QDir::homePath(),tr("Images (*.png *.xpm *.jpeg *.jpg)") );

        if(!s.isNull()) {
            imwrite(s.toStdString(), result);
            QMessageBox::information(this, tr("Result saved"), tr("Good job"));
            ui->loadPushButton->setEnabled(true);
            ui->savePushButton->setEnabled(false);
            ui->doPushButton->setEnabled(false);
            ui->resetPushButton->setEnabled(true);
        } else {
            QMessageBox::information(this, tr("Unable to save file"), tr("Sorry !"));

        }
    }
}

void MainWindow::on_exitPushButton_clicked(){
    QMessageBox msgBox;

    int ret = msgBox.information(this, tr("Exit"), tr("Are you sure to quit the app?"), QMessageBox::Yes | QMessageBox::No);

    switch (ret) {
      case QMessageBox::No :
        break;
      case QMessageBox::Yes :
            MainWindow::connect(ui->exitPushButton,SIGNAL(clicked()), qApp,SLOT(quit()));
        break;
      default:
          break;
    }
}


void MainWindow::on_actionDescription_triggered()
{
    QMessageBox::information(this, tr("Description"), tr("Qt C++ with OpenCV desktop application (version 1.0.0)\nImages segmentation by implementing the watershed algorithm.\nLicense : GNU GPL v3.0."));
}
