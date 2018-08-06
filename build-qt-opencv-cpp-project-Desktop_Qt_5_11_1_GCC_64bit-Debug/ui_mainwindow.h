/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDescription;
    QAction *actionMohamed_Aimane_SKHAIRI;
    QAction *actionmedaimane_github_io;
    QAction *actionskhairimedaimane_gmail_com;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *doPushButton;
    QPushButton *resetPushButton;
    QPushButton *exitPushButton;
    QLabel *label;
    QPushButton *loadPushButton;
    QPushButton *savePushButton;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuAuthor;
    QMenu *menuContact;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 500);
        MainWindow->setMinimumSize(QSize(500, 500));
        MainWindow->setMaximumSize(QSize(900, 900));
        MainWindow->setStyleSheet(QStringLiteral("background-image : url('assets/img/back.png')"));
        actionDescription = new QAction(MainWindow);
        actionDescription->setObjectName(QStringLiteral("actionDescription"));
        actionMohamed_Aimane_SKHAIRI = new QAction(MainWindow);
        actionMohamed_Aimane_SKHAIRI->setObjectName(QStringLiteral("actionMohamed_Aimane_SKHAIRI"));
        actionmedaimane_github_io = new QAction(MainWindow);
        actionmedaimane_github_io->setObjectName(QStringLiteral("actionmedaimane_github_io"));
        actionskhairimedaimane_gmail_com = new QAction(MainWindow);
        actionskhairimedaimane_gmail_com->setObjectName(QStringLiteral("actionskhairimedaimane_gmail_com"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 60, 321, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(100, 20, 100, 20);
        doPushButton = new QPushButton(gridLayoutWidget);
        doPushButton->setObjectName(QStringLiteral("doPushButton"));
        doPushButton->setEnabled(false);

        gridLayout->addWidget(doPushButton, 3, 0, 1, 1);

        resetPushButton = new QPushButton(gridLayoutWidget);
        resetPushButton->setObjectName(QStringLiteral("resetPushButton"));
        resetPushButton->setEnabled(false);

        gridLayout->addWidget(resetPushButton, 2, 0, 1, 1);

        exitPushButton = new QPushButton(gridLayoutWidget);
        exitPushButton->setObjectName(QStringLiteral("exitPushButton"));

        gridLayout->addWidget(exitPushButton, 5, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(20, 20));
        label->setBaseSize(QSize(5, 5));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        loadPushButton = new QPushButton(gridLayoutWidget);
        loadPushButton->setObjectName(QStringLiteral("loadPushButton"));

        gridLayout->addWidget(loadPushButton, 1, 0, 1, 1);

        savePushButton = new QPushButton(gridLayoutWidget);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));
        savePushButton->setEnabled(false);

        gridLayout->addWidget(savePushButton, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 22));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuAuthor = new QMenu(menuAbout);
        menuAuthor->setObjectName(QStringLiteral("menuAuthor"));
        menuContact = new QMenu(menuAbout);
        menuContact->setObjectName(QStringLiteral("menuContact"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionDescription);
        menuAbout->addSeparator();
        menuAbout->addAction(menuAuthor->menuAction());
        menuAbout->addSeparator();
        menuAbout->addAction(menuContact->menuAction());
        menuAbout->addSeparator();
        menuAuthor->addSeparator();
        menuAuthor->addAction(actionMohamed_Aimane_SKHAIRI);
        menuAuthor->addSeparator();
        menuContact->addSeparator();
        menuContact->addSeparator();
        menuContact->addAction(actionmedaimane_github_io);
        menuContact->addSeparator();
        menuContact->addAction(actionskhairimedaimane_gmail_com);
        menuContact->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Segmentation", nullptr));
        actionDescription->setText(QApplication::translate("MainWindow", "Description", nullptr));
        actionMohamed_Aimane_SKHAIRI->setText(QApplication::translate("MainWindow", "Mohamed Aimane SKHAIRI", nullptr));
        actionmedaimane_github_io->setText(QApplication::translate("MainWindow", "medaimane.github.io", nullptr));
        actionskhairimedaimane_gmail_com->setText(QApplication::translate("MainWindow", "skhairimedaimane@gmail.com", nullptr));
        doPushButton->setText(QApplication::translate("MainWindow", "Do watershed", nullptr));
        resetPushButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        exitPushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Menu", nullptr));
        loadPushButton->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        savePushButton->setText(QApplication::translate("MainWindow", "Save Image", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
        menuAuthor->setTitle(QApplication::translate("MainWindow", "Author", nullptr));
        menuContact->setTitle(QApplication::translate("MainWindow", "Contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
