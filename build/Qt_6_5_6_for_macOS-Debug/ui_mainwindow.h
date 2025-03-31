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
#include <QtWidgets/QRadioButton>
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
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QPushButton *laser_act_b;
    QLineEdit *lineEdit;
    QPushButton *ext_radiation_b;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QComboBox *measure_mode;
    QPushButton *pointer_b;
    QPushButton *break_range_b;
    QPushButton *term_control_b;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *start_range_b;
    QLabel *label_6;
    QPushButton *pulse_b;
    QGridLayout *gridLayout;
    QLineEdit *horizont_marker_input;
    QLabel *horizontal_mark;
    QLineEdit *omega_horizontal_input;
    QLabel *omega_horizontal;
    QLineEdit *vertical_marker_input;
    QLabel *vertical_mark;
    QLineEdit *omega_vertical_input;
    QLabel *omega_vertical;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *up_b;
    QPushButton *up_2_b;
    QVBoxLayout *verticalLayout_5;
    QPushButton *l_l;
    QPushButton *l_2_b;
    QPushButton *stop_b;
    QVBoxLayout *verticalLayout_8;
    QPushButton *r_b;
    QPushButton *r_2_b;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *d_2_b;
    QPushButton *d_b;
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

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 1, 1, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        laser_act_b = new QPushButton(frame);
        laser_act_b->setObjectName("laser_act_b");
        laser_act_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: none; /* \320\224\320\265\321\204\320\276\320\273\321\202\320\275\320\270\320\271 \320\272\320\276\320\273\321\226\321\200 */\n"
"    border: none;\n"
"    color: black;\n"
"    border-left: 1px solid gray;\n"
"    border-right: 1px solid gray;\n"
"	border-top:1px solid gray;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* \320\233\320\265\320\263\320\272\320\265 \320\267\320\260\321\202\320\265\320\274\320\275\320\265\320\275\320\275\321\217 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: rgb(130, 170, 90); /* \320\227\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\321\202\320\270\321\201\320\272\320\260\320\275\320\275\321\226 */\n"
"    border-left: 1px solid rgb(110, 144, 76);\n"
"    border-right: 1px solid rgb(110, 144, 76);\n"
"    bo"
                        "rder-bottom: 1px solid rgb(110, 144, 76);\n"
"	border-top: 1px solid rgb(110, 144, 76);\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: rgb(138, 181, 96); /* \320\241\320\262\321\226\321\202\320\273\321\226\321\210\320\270\320\271 \320\267\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 \320\262 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\320\274\321\203 \321\201\321\202\320\260\320\275\321\226 */\n"
"}\n"
""));
        laser_act_b->setCheckable(true);

        gridLayout_4->addWidget(laser_act_b, 0, 0, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");

        gridLayout_4->addWidget(lineEdit, 2, 1, 1, 1, Qt::AlignHCenter);

        ext_radiation_b = new QPushButton(frame);
        ext_radiation_b->setObjectName("ext_radiation_b");
        ext_radiation_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: none; /* \320\224\320\265\321\204\320\276\320\273\321\202\320\275\320\270\320\271 \320\272\320\276\320\273\321\226\321\200 */\n"
"    border: none;\n"
"    color: black;\n"
"    border-left: 1px solid gray;\n"
"    border-right: 1px solid gray;\n"
"	border-top:1px solid gray;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* \320\233\320\265\320\263\320\272\320\265 \320\267\320\260\321\202\320\265\320\274\320\275\320\265\320\275\320\275\321\217 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: rgb(130, 170, 90); /* \320\227\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\321\202\320\270\321\201\320\272\320\260\320\275\320\275\321\226 */\n"
"    border-left: 1px solid rgb(110, 144, 76);\n"
"    border-right: 1px solid rgb(110, 144, 76);\n"
"    bo"
                        "rder-bottom: 1px solid rgb(110, 144, 76);\n"
"	border-top: 1px solid rgb(110, 144, 76);\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: rgb(138, 181, 96); /* \320\241\320\262\321\226\321\202\320\273\321\226\321\210\320\270\320\271 \320\267\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 \320\262 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\320\274\321\203 \321\201\321\202\320\260\320\275\321\226 */\n"
"}\n"
""));
        ext_radiation_b->setCheckable(true);

        gridLayout_4->addWidget(ext_radiation_b, 0, 3, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout_5->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton = new QRadioButton(frame);
        radioButton->setObjectName("radioButton");

        gridLayout_5->addWidget(radioButton, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(frame);
        radioButton_3->setObjectName("radioButton_3");

        gridLayout_5->addWidget(radioButton_3, 1, 1, 1, 1);

        radioButton_4 = new QRadioButton(frame);
        radioButton_4->setObjectName("radioButton_4");

        gridLayout_5->addWidget(radioButton_4, 2, 0, 1, 1);

        radioButton_5 = new QRadioButton(frame);
        radioButton_5->setObjectName("radioButton_5");

        gridLayout_5->addWidget(radioButton_5, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 2, 3, 1, 1);

        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout_4->addWidget(comboBox, 2, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 4, 0, 1, 1, Qt::AlignHCenter);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_4->addWidget(lineEdit_2, 2, 2, 1, 1, Qt::AlignHCenter);

        measure_mode = new QComboBox(frame);
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->setObjectName("measure_mode");

        gridLayout_4->addWidget(measure_mode, 4, 1, 1, 1);

        pointer_b = new QPushButton(frame);
        pointer_b->setObjectName("pointer_b");
        pointer_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: none; /* Default color */\n"
"    border: none;\n"
"    color: black;\n"
"    border-left: 1px solid gray;\n"
"    border-right: 1px solid gray;\n"
"    border-top: 1px solid gray;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* Light darkening on hover */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: rgb(255, 140, 0); /* Orange color when clicked */\n"
"    border-left: 1px solid rgb(204, 113, 0);\n"
"    border-right: 1px solid rgb(204, 113, 0);\n"
"    border-bottom: 1px solid rgb(204, 113, 0);\n"
"    border-top: 1px solid rgb(204, 113, 0);\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: rgb(255, 165, 0); /* Lighter orange when hovered in active state */\n"
"}\n"
""));
        pointer_b->setCheckable(true);

        gridLayout_4->addWidget(pointer_b, 3, 2, 1, 1);

        break_range_b = new QPushButton(frame);
        break_range_b->setObjectName("break_range_b");

        gridLayout_4->addWidget(break_range_b, 3, 1, 1, 1);

        term_control_b = new QPushButton(frame);
        term_control_b->setObjectName("term_control_b");
        term_control_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: none; /* \320\224\320\265\321\204\320\276\320\273\321\202\320\275\320\270\320\271 \320\272\320\276\320\273\321\226\321\200 */\n"
"    border: none;\n"
"    color: black;\n"
"    border-left: 1px solid gray;\n"
"    border-right: 1px solid gray;\n"
"	border-top:1px solid gray;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* \320\233\320\265\320\263\320\272\320\265 \320\267\320\260\321\202\320\265\320\274\320\275\320\265\320\275\320\275\321\217 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: rgb(130, 170, 90); /* \320\227\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\321\202\320\270\321\201\320\272\320\260\320\275\320\275\321\226 */\n"
"    border-left: 1px solid rgb(110, 144, 76);\n"
"    border-right: 1px solid rgb(110, 144, 76);\n"
"    bo"
                        "rder-bottom: 1px solid rgb(110, 144, 76);\n"
"	border-top: 1px solid rgb(110, 144, 76);\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: rgb(138, 181, 96); /* \320\241\320\262\321\226\321\202\320\273\321\226\321\210\320\270\320\271 \320\267\320\265\320\273\320\265\320\275\320\270\320\271 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 \320\262 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\320\274\321\203 \321\201\321\202\320\260\320\275\321\226 */\n"
"}\n"
""));
        term_control_b->setCheckable(true);

        gridLayout_4->addWidget(term_control_b, 0, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 1, 3, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        start_range_b = new QPushButton(frame);
        start_range_b->setObjectName("start_range_b");

        gridLayout_4->addWidget(start_range_b, 3, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        pulse_b = new QPushButton(frame);
        pulse_b->setObjectName("pulse_b");
        pulse_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: none; /* \320\224\320\265\321\204\320\276\320\273\321\202\320\275\320\270\320\271 \320\272\320\276\320\273\321\226\321\200 */\n"
"    border: none;\n"
"    color: black;\n"
"    border-left: 1px solid gray;\n"
"    border-right: 1px solid gray;\n"
"	border-top:1px solid gray;\n"
"    border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* \320\233\320\265\320\263\320\272\320\265 \320\267\320\260\321\202\320\265\320\274\320\275\320\265\320\275\320\275\321\217 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\275\321\226 */\n"
"}\n"
"\n"
""));
        pulse_b->setCheckable(true);

        gridLayout_4->addWidget(pulse_b, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizont_marker_input = new QLineEdit(frame);
        horizont_marker_input->setObjectName("horizont_marker_input");

        gridLayout->addWidget(horizont_marker_input, 1, 1, 1, 1, Qt::AlignLeft);

        horizontal_mark = new QLabel(frame);
        horizontal_mark->setObjectName("horizontal_mark");

        gridLayout->addWidget(horizontal_mark, 1, 0, 1, 1, Qt::AlignRight);

        omega_horizontal_input = new QLineEdit(frame);
        omega_horizontal_input->setObjectName("omega_horizontal_input");

        gridLayout->addWidget(omega_horizontal_input, 3, 1, 1, 1, Qt::AlignLeft);

        omega_horizontal = new QLabel(frame);
        omega_horizontal->setObjectName("omega_horizontal");

        gridLayout->addWidget(omega_horizontal, 3, 0, 1, 1, Qt::AlignRight);

        vertical_marker_input = new QLineEdit(frame);
        vertical_marker_input->setObjectName("vertical_marker_input");

        gridLayout->addWidget(vertical_marker_input, 2, 1, 1, 1, Qt::AlignLeft);

        vertical_mark = new QLabel(frame);
        vertical_mark->setObjectName("vertical_mark");

        gridLayout->addWidget(vertical_mark, 2, 0, 1, 1, Qt::AlignRight);

        omega_vertical_input = new QLineEdit(frame);
        omega_vertical_input->setObjectName("omega_vertical_input");

        gridLayout->addWidget(omega_vertical_input, 4, 1, 1, 1, Qt::AlignLeft);

        omega_vertical = new QLabel(frame);
        omega_vertical->setObjectName("omega_vertical");

        gridLayout->addWidget(omega_vertical, 4, 0, 1, 1, Qt::AlignRight);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        up_b = new QPushButton(frame);
        up_b->setObjectName("up_b");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(up_b->sizePolicy().hasHeightForWidth());
        up_b->setSizePolicy(sizePolicy3);
        up_b->setMinimumSize(QSize(0, 0));
        up_b->setSizeIncrement(QSize(0, 0));
        up_b->setBaseSize(QSize(0, 0));

        horizontalLayout_3->addWidget(up_b, 0, Qt::AlignRight|Qt::AlignBottom);

        up_2_b = new QPushButton(frame);
        up_2_b->setObjectName("up_2_b");
        up_2_b->setMinimumSize(QSize(0, 0));
        up_2_b->setMaximumSize(QSize(16777215, 16777215));
        up_2_b->setStyleSheet(QString::fromUtf8("QPushButton:pressed{\n"
"	background-color:rgb(127,12,335);\n"
"	border:none;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(up_2_b, 0, Qt::AlignLeft|Qt::AlignBottom);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        l_l = new QPushButton(frame);
        l_l->setObjectName("l_l");
        l_l->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(l_l, 0, Qt::AlignRight);

        l_2_b = new QPushButton(frame);
        l_2_b->setObjectName("l_2_b");
        l_2_b->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(l_2_b, 0, Qt::AlignRight);


        gridLayout_3->addLayout(verticalLayout_5, 2, 1, 1, 1);

        stop_b = new QPushButton(frame);
        stop_b->setObjectName("stop_b");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stop_b->sizePolicy().hasHeightForWidth());
        stop_b->setSizePolicy(sizePolicy4);
        stop_b->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(stop_b, 2, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        r_b = new QPushButton(frame);
        r_b->setObjectName("r_b");
        r_b->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(r_b, 0, Qt::AlignLeft);

        r_2_b = new QPushButton(frame);
        r_2_b->setObjectName("r_2_b");
        r_2_b->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(r_2_b, 0, Qt::AlignLeft);


        gridLayout_3->addLayout(verticalLayout_8, 2, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        d_2_b = new QPushButton(frame);
        d_2_b->setObjectName("d_2_b");
        d_2_b->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(d_2_b, 0, Qt::AlignRight|Qt::AlignTop);

        d_b = new QPushButton(frame);
        d_b->setObjectName("d_b");
        d_b->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(d_b, 0, Qt::AlignLeft|Qt::AlignTop);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


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
        label_5->setText(QCoreApplication::translate("MainWindow", "Time remaining", nullptr));
        laser_act_b->setText(QCoreApplication::translate("MainWindow", "LASER \n"
"ACTIVATION", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        ext_radiation_b->setText(QCoreApplication::translate("MainWindow", "External\n"
" radiation", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ENERGY", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1 Hz", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2 Hz", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3 Hz", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4 Hz", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Mesurement mode", nullptr));
        lineEdit_2->setText(QString());
        measure_mode->setItemText(0, QCoreApplication::translate("MainWindow", "SMM", nullptr));
        measure_mode->setItemText(1, QCoreApplication::translate("MainWindow", "...", nullptr));

        pointer_b->setText(QCoreApplication::translate("MainWindow", "Pointer", nullptr));
        break_range_b->setText(QCoreApplication::translate("MainWindow", "Break range", nullptr));
        term_control_b->setText(QCoreApplication::translate("MainWindow", "Thermal \n"
"control", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "pulse frequency", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Error: NONE", nullptr));
        start_range_b->setText(QCoreApplication::translate("MainWindow", "start range", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Temperature \302\260C", nullptr));
        pulse_b->setText(QCoreApplication::translate("MainWindow", "PULSE\n"
" ON", nullptr));
        horizontal_mark->setText(QCoreApplication::translate("MainWindow", "horizontal marker", nullptr));
        omega_horizontal->setText(QCoreApplication::translate("MainWindow", "\317\211 H", nullptr));
        vertical_mark->setText(QCoreApplication::translate("MainWindow", "vertical marker", nullptr));
        omega_vertical->setText(QCoreApplication::translate("MainWindow", "\317\211 V", nullptr));
        up_b->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        up_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\210", nullptr));
        l_l->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        l_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\207", nullptr));
        stop_b->setText(QCoreApplication::translate("MainWindow", ">0<", nullptr));
        r_b->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        r_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\211", nullptr));
        d_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\212", nullptr));
        d_b->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
