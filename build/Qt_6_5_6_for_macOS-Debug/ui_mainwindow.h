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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QGridLayout *gridLayout_2;
    QLabel *videoLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *videoLabel2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *l_vid_turn;
    QPushButton *r_vid_turn;
    QPushButton *start_b;
    QPushButton *stop_b_2;
    QPushButton *switch_vid;
    QGridLayout *gridLayout;
    QLabel *multi_label_2;
    QLineEdit *horizont_marker_input;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *vertical_marker_input;
    QLabel *multi_label_1;
    QGridLayout *gridLayout_3;
    QPushButton *up_b;
    QPushButton *d_2_b;
    QPushButton *l_l;
    QPushButton *l_2_b;
    QPushButton *r_b;
    QPushButton *d_b;
    QPushButton *up_2_b;
    QPushButton *r_2_b;
    QPushButton *stop_b;
    QGridLayout *gridLayout_4;
    QPushButton *break_range;
    QPushButton *start_range;
    QPushButton *pushButton_7;
    QLabel *label;
    QComboBox *measure_mode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1950, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        videoLabel = new QLabel(centralwidget);
        videoLabel->setObjectName("videoLabel");
        videoLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy);
        videoLabel->setMinimumSize(QSize(0, 0));
        videoLabel->setAutoFillBackground(false);

        gridLayout_2->addWidget(videoLabel, 0, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        videoLabel2 = new QLabel(frame);
        videoLabel2->setObjectName("videoLabel2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(videoLabel2->sizePolicy().hasHeightForWidth());
        videoLabel2->setSizePolicy(sizePolicy2);
        videoLabel2->setMinimumSize(QSize(240, 192));
        videoLabel2->setMaximumSize(QSize(400, 16777215));

        verticalLayout->addWidget(videoLabel2, 0, Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        l_vid_turn = new QPushButton(frame);
        l_vid_turn->setObjectName("l_vid_turn");
        l_vid_turn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(l_vid_turn);

        r_vid_turn = new QPushButton(frame);
        r_vid_turn->setObjectName("r_vid_turn");
        r_vid_turn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(r_vid_turn);

        start_b = new QPushButton(frame);
        start_b->setObjectName("start_b");

        horizontalLayout_2->addWidget(start_b);

        stop_b_2 = new QPushButton(frame);
        stop_b_2->setObjectName("stop_b_2");

        horizontalLayout_2->addWidget(stop_b_2);

        switch_vid = new QPushButton(frame);
        switch_vid->setObjectName("switch_vid");

        horizontalLayout_2->addWidget(switch_vid);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        multi_label_2 = new QLabel(frame);
        multi_label_2->setObjectName("multi_label_2");
        multi_label_2->setFrameShape(QFrame::Box);

        gridLayout->addWidget(multi_label_2, 3, 1, 1, 1, Qt::AlignLeft|Qt::AlignTop);

        horizont_marker_input = new QLineEdit(frame);
        horizont_marker_input->setObjectName("horizont_marker_input");

        gridLayout->addWidget(horizont_marker_input, 1, 1, 1, 1, Qt::AlignRight);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        vertical_marker_input = new QLineEdit(frame);
        vertical_marker_input->setObjectName("vertical_marker_input");

        gridLayout->addWidget(vertical_marker_input, 2, 1, 1, 1, Qt::AlignRight);

        multi_label_1 = new QLabel(frame);
        multi_label_1->setObjectName("multi_label_1");
        multi_label_1->setFrameShape(QFrame::Box);
        multi_label_1->setWordWrap(true);

        gridLayout->addWidget(multi_label_1, 3, 0, 1, 1, Qt::AlignLeft|Qt::AlignTop);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        up_b = new QPushButton(frame);
        up_b->setObjectName("up_b");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(up_b->sizePolicy().hasHeightForWidth());
        up_b->setSizePolicy(sizePolicy3);
        up_b->setMinimumSize(QSize(40, 40));
        up_b->setSizeIncrement(QSize(0, 0));
        up_b->setBaseSize(QSize(0, 0));

        gridLayout_3->addWidget(up_b, 0, 1, 1, 1);

        d_2_b = new QPushButton(frame);
        d_2_b->setObjectName("d_2_b");
        d_2_b->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(d_2_b, 3, 1, 1, 1);

        l_l = new QPushButton(frame);
        l_l->setObjectName("l_l");
        l_l->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(l_l, 1, 0, 1, 1);

        l_2_b = new QPushButton(frame);
        l_2_b->setObjectName("l_2_b");
        l_2_b->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(l_2_b, 2, 0, 1, 1);

        r_b = new QPushButton(frame);
        r_b->setObjectName("r_b");
        r_b->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(r_b, 1, 3, 1, 1);

        d_b = new QPushButton(frame);
        d_b->setObjectName("d_b");
        d_b->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(d_b, 3, 2, 1, 1);

        up_2_b = new QPushButton(frame);
        up_2_b->setObjectName("up_2_b");
        up_2_b->setMinimumSize(QSize(40, 40));
        up_2_b->setMaximumSize(QSize(40, 40));
        up_2_b->setStyleSheet(QString::fromUtf8("QPushButton:pressed{\n"
"	background-color:rgb(127,12,335);\n"
"	border:none;\n"
"}\n"
""));

        gridLayout_3->addWidget(up_2_b, 0, 2, 1, 1);

        r_2_b = new QPushButton(frame);
        r_2_b->setObjectName("r_2_b");
        r_2_b->setMinimumSize(QSize(40, 40));

        gridLayout_3->addWidget(r_2_b, 2, 3, 1, 1);

        stop_b = new QPushButton(frame);
        stop_b->setObjectName("stop_b");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stop_b->sizePolicy().hasHeightForWidth());
        stop_b->setSizePolicy(sizePolicy4);
        stop_b->setMinimumSize(QSize(60, 60));

        gridLayout_3->addWidget(stop_b, 1, 1, 2, 2);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        break_range = new QPushButton(frame);
        break_range->setObjectName("break_range");

        gridLayout_4->addWidget(break_range, 0, 1, 1, 1);

        start_range = new QPushButton(frame);
        start_range->setObjectName("start_range");

        gridLayout_4->addWidget(start_range, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout_4->addWidget(pushButton_7, 0, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        measure_mode = new QComboBox(frame);
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->setObjectName("measure_mode");

        gridLayout_4->addWidget(measure_mode, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        gridLayout_2->addWidget(frame, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

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
        videoLabel->setText(QString());
        videoLabel2->setText(QString());
        l_vid_turn->setText(QCoreApplication::translate("MainWindow", "\342\237\262", nullptr));
        r_vid_turn->setText(QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
        start_b->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        stop_b_2->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        switch_vid->setText(QCoreApplication::translate("MainWindow", "Switch Videos", nullptr));
        multi_label_2->setText(QCoreApplication::translate("MainWindow", "<html>\n"
"  <head/>\n"
"  <body>\n"
"    <p>Multilabel_2</p>\n"
"    <p>line_2</p>\n"
"    <p>line_3</p>\n"
"    <p>line_4</p>\n"
"    <p>line_5</p>\n"
"    <p>line_6</p>\n"
"  </body>\n"
"</html>\n"
"", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "horizontal marker", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "vertical marker", nullptr));
        multi_label_1->setText(QCoreApplication::translate("MainWindow", "<html>\n"
"  <head/>\n"
"  <body>\n"
"    <p>Multilabel_1</p>\n"
"    <p>line_2</p>\n"
"    <p>line_3</p>\n"
"    <p>line_4</p>\n"
"    <p>line_5</p>\n"
"    <p>line_6</p>\n"
"  </body>\n"
"</html>\n"
"", nullptr));
        up_b->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        d_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\212", nullptr));
        l_l->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        l_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\207", nullptr));
        r_b->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        d_b->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        up_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\210", nullptr));
        r_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\211", nullptr));
        stop_b->setText(QCoreApplication::translate("MainWindow", ">0<", nullptr));
        break_range->setText(QCoreApplication::translate("MainWindow", "Break range", nullptr));
        start_range->setText(QCoreApplication::translate("MainWindow", "start range", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Pointer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mesurement mode", nullptr));
        measure_mode->setItemText(0, QCoreApplication::translate("MainWindow", "SMM", nullptr));
        measure_mode->setItemText(1, QCoreApplication::translate("MainWindow", "...", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
