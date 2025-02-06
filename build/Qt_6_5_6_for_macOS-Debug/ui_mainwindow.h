/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *videoLabel;
    QLabel *videoLabel2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1950, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_6 = new QFrame(centralwidget);
        frame_6->setObjectName("frame_6");
        QFont font;
        font.setKerning(true);
        frame_6->setFont(font);
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(1);
        verticalLayout_6 = new QVBoxLayout(frame_6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        frame = new QFrame(frame_6);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(12, -1, -1, -1);
        startButton = new QPushButton(frame);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(200, 0));
        startButton->setMaximumSize(QSize(200, 100));

        horizontalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(frame);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(200, 50));
        stopButton->setMaximumSize(QSize(200, 100));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout_6->addWidget(frame, 0, Qt::AlignLeft|Qt::AlignTop);

        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName("frame_5");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(0, 0));
        frame_5->setAutoFillBackground(true);
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        videoLabel = new QLabel(frame_5);
        videoLabel->setObjectName("videoLabel");
        videoLabel->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy1);
        videoLabel->setMinimumSize(QSize(0, 0));
        videoLabel->setAutoFillBackground(false);

        gridLayout_3->addWidget(videoLabel, 0, 0, 1, 1);

        videoLabel2 = new QLabel(frame_5);
        videoLabel2->setObjectName("videoLabel2");

        gridLayout_3->addWidget(videoLabel2, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);


        verticalLayout_6->addWidget(frame_5);


        horizontalLayout->addWidget(frame_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1950, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        videoLabel->setText(QString());
        videoLabel2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
