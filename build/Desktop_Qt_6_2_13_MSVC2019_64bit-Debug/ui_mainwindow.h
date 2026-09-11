/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
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
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickable.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    ClickableLabel *videoLabel;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QLabel *vert_out;
    QLabel *label_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *videoLabel2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *l_vid_turn;
    QPushButton *start_b;
    QPushButton *stop_b_2;
    QPushButton *switch_vid;
    QPushButton *pushButton;
    QGridLayout *gridLayout_4;
    QPushButton *break_range_b;
    QLabel *label;
    QPushButton *pulse_b;
    QLineEdit *temp_out;
    QComboBox *measure_mode;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *laser_act_b;
    QLabel *error_label;
    QPushButton *start_range_b;
    QLineEdit *time_remaining_out;
    QPushButton *pointer_b;
    QComboBox *frequency_mode;
    QLabel *label_6;
    QPushButton *ext_radiation_b;
    QPushButton *term_control_b;
    QLineEdit *range_out;
    QPushButton *get_frequency;
    QLineEdit *frequency_out;
    QGridLayout *gridLayout_7;
    QComboBox *third_STANAG;
    QComboBox *second_STANAG;
    QComboBox *first_STANAG;
    QLabel *label_3;
    QPushButton *get_stanag;
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
    QGridLayout *gridLayout_9;
    QLabel *label_2;
    QComboBox *mode_input;
    QGridLayout *gridLayout_10;
    QLabel *label_7;
    QComboBox *step_input;
    QGridLayout *gridLayout_12;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *hor_out;
    QLabel *status_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1950, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal {\n"
"    background: red;\n"
"    width: 10px;\n"
"    margin: -2px 0;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        horizontalSlider->setMinimum(-300);
        horizontalSlider->setMaximum(300);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksAbove);
        horizontalSlider->setTickInterval(100);

        gridLayout_2->addWidget(horizontalSlider, 2, 1, 1, 1);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical {\n"
"    background: red;\n"
"    height: 14px;\n"
"    margin: 0 -2px;\n"
"    border-radius: 5px;\n"
"}"));
        verticalSlider->setMinimum(-200);
        verticalSlider->setMaximum(200);
        verticalSlider->setSingleStep(1);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        verticalSlider->setTickPosition(QSlider::TickPosition::TicksAbove);
        verticalSlider->setTickInterval(100);

        gridLayout_2->addWidget(verticalSlider, 3, 2, 1, 1);

        videoLabel = new ClickableLabel(centralwidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy);
        videoLabel->setMinimumSize(QSize(0, 0));
        videoLabel->setAutoFillBackground(false);
        videoLabel->setFrameShape(QFrame::Shape::NoFrame);

        gridLayout_2->addWidget(videoLabel, 3, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14, 0, Qt::AlignmentFlag::AlignTop);

        vert_out = new QLabel(centralwidget);
        vert_out->setObjectName(QString::fromUtf8("vert_out"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vert_out->sizePolicy().hasHeightForWidth());
        vert_out->setSizePolicy(sizePolicy1);
        vert_out->setMinimumSize(QSize(40, 0));
        vert_out->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setPointSize(17);
        vert_out->setFont(font);

        verticalLayout_4->addWidget(vert_out, 0, Qt::AlignmentFlag::AlignVCenter);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11, 0, Qt::AlignmentFlag::AlignBottom);


        gridLayout_2->addLayout(verticalLayout_4, 3, 3, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        videoLabel2 = new QLabel(frame);
        videoLabel2->setObjectName(QString::fromUtf8("videoLabel2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(videoLabel2->sizePolicy().hasHeightForWidth());
        videoLabel2->setSizePolicy(sizePolicy3);
        videoLabel2->setMinimumSize(QSize(240, 192));
        videoLabel2->setMaximumSize(QSize(400, 16777215));

        verticalLayout->addWidget(videoLabel2, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        l_vid_turn = new QPushButton(frame);
        l_vid_turn->setObjectName(QString::fromUtf8("l_vid_turn"));
        l_vid_turn->setMaximumSize(QSize(50, 16777215));
        l_vid_turn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        l_vid_turn->setCheckable(true);

        horizontalLayout_2->addWidget(l_vid_turn);

        start_b = new QPushButton(frame);
        start_b->setObjectName(QString::fromUtf8("start_b"));
        start_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(start_b);

        stop_b_2 = new QPushButton(frame);
        stop_b_2->setObjectName(QString::fromUtf8("stop_b_2"));
        stop_b_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(stop_b_2);

        switch_vid = new QPushButton(frame);
        switch_vid->setObjectName(QString::fromUtf8("switch_vid"));
        switch_vid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(switch_vid);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        break_range_b = new QPushButton(frame);
        break_range_b->setObjectName(QString::fromUtf8("break_range_b"));
        break_range_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(break_range_b, 5, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 6, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        pulse_b = new QPushButton(frame);
        pulse_b->setObjectName(QString::fromUtf8("pulse_b"));
        pulse_b->setEnabled(true);
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

        temp_out = new QLineEdit(frame);
        temp_out->setObjectName(QString::fromUtf8("temp_out"));
        temp_out->setEnabled(true);

        gridLayout_4->addWidget(temp_out, 2, 2, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        measure_mode = new QComboBox(frame);
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->addItem(QString());
        measure_mode->setObjectName(QString::fromUtf8("measure_mode"));

        gridLayout_4->addWidget(measure_mode, 6, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 1, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        laser_act_b = new QPushButton(frame);
        laser_act_b->setObjectName(QString::fromUtf8("laser_act_b"));
        laser_act_b->setEnabled(true);
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

        error_label = new QLabel(frame);
        error_label->setObjectName(QString::fromUtf8("error_label"));

        gridLayout_4->addWidget(error_label, 1, 3, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        start_range_b = new QPushButton(frame);
        start_range_b->setObjectName(QString::fromUtf8("start_range_b"));
        start_range_b->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(start_range_b, 5, 0, 1, 1);

        time_remaining_out = new QLineEdit(frame);
        time_remaining_out->setObjectName(QString::fromUtf8("time_remaining_out"));

        gridLayout_4->addWidget(time_remaining_out, 2, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        pointer_b = new QPushButton(frame);
        pointer_b->setObjectName(QString::fromUtf8("pointer_b"));
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

        gridLayout_4->addWidget(pointer_b, 5, 2, 1, 1);

        frequency_mode = new QComboBox(frame);
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->addItem(QString());
        frequency_mode->setObjectName(QString::fromUtf8("frequency_mode"));
        frequency_mode->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(frequency_mode, 2, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 1, 2, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        ext_radiation_b = new QPushButton(frame);
        ext_radiation_b->setObjectName(QString::fromUtf8("ext_radiation_b"));
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

        term_control_b = new QPushButton(frame);
        term_control_b->setObjectName(QString::fromUtf8("term_control_b"));
        term_control_b->setEnabled(false);
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

        range_out = new QLineEdit(frame);
        range_out->setObjectName(QString::fromUtf8("range_out"));

        gridLayout_4->addWidget(range_out, 6, 2, 1, 1, Qt::AlignmentFlag::AlignLeft);

        get_frequency = new QPushButton(frame);
        get_frequency->setObjectName(QString::fromUtf8("get_frequency"));
        get_frequency->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(get_frequency, 4, 2, 1, 1);

        frequency_out = new QLineEdit(frame);
        frequency_out->setObjectName(QString::fromUtf8("frequency_out"));

        gridLayout_4->addWidget(frequency_out, 4, 3, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(0);
        third_STANAG = new QComboBox(frame);
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->setObjectName(QString::fromUtf8("third_STANAG"));
        third_STANAG->setMaximumSize(QSize(50, 16777215));

        gridLayout_7->addWidget(third_STANAG, 1, 4, 1, 1);

        second_STANAG = new QComboBox(frame);
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->setObjectName(QString::fromUtf8("second_STANAG"));
        second_STANAG->setMaximumSize(QSize(50, 16777215));

        gridLayout_7->addWidget(second_STANAG, 1, 3, 1, 1, Qt::AlignmentFlag::AlignRight);

        first_STANAG = new QComboBox(frame);
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->setObjectName(QString::fromUtf8("first_STANAG"));
        first_STANAG->setMaximumSize(QSize(50, 16777215));

        gridLayout_7->addWidget(first_STANAG, 1, 2, 1, 1, Qt::AlignmentFlag::AlignRight);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(10, 16777215));

        gridLayout_7->addWidget(label_3, 1, 1, 1, 1, Qt::AlignmentFlag::AlignRight);


        gridLayout_4->addLayout(gridLayout_7, 4, 0, 1, 1);

        get_stanag = new QPushButton(frame);
        get_stanag->setObjectName(QString::fromUtf8("get_stanag"));
        get_stanag->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_4->addWidget(get_stanag, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizont_marker_input = new QLineEdit(frame);
        horizont_marker_input->setObjectName(QString::fromUtf8("horizont_marker_input"));
        horizont_marker_input->setEnabled(true);

        gridLayout->addWidget(horizont_marker_input, 1, 1, 1, 1, Qt::AlignmentFlag::AlignLeft);

        horizontal_mark = new QLabel(frame);
        horizontal_mark->setObjectName(QString::fromUtf8("horizontal_mark"));

        gridLayout->addWidget(horizontal_mark, 1, 0, 1, 1, Qt::AlignmentFlag::AlignRight);

        omega_horizontal_input = new QLineEdit(frame);
        omega_horizontal_input->setObjectName(QString::fromUtf8("omega_horizontal_input"));
        omega_horizontal_input->setEnabled(true);

        gridLayout->addWidget(omega_horizontal_input, 3, 1, 1, 1, Qt::AlignmentFlag::AlignLeft);

        omega_horizontal = new QLabel(frame);
        omega_horizontal->setObjectName(QString::fromUtf8("omega_horizontal"));

        gridLayout->addWidget(omega_horizontal, 3, 0, 1, 1, Qt::AlignmentFlag::AlignRight);

        vertical_marker_input = new QLineEdit(frame);
        vertical_marker_input->setObjectName(QString::fromUtf8("vertical_marker_input"));
        vertical_marker_input->setEnabled(true);

        gridLayout->addWidget(vertical_marker_input, 2, 1, 1, 1, Qt::AlignmentFlag::AlignLeft);

        vertical_mark = new QLabel(frame);
        vertical_mark->setObjectName(QString::fromUtf8("vertical_mark"));

        gridLayout->addWidget(vertical_mark, 2, 0, 1, 1, Qt::AlignmentFlag::AlignRight);

        omega_vertical_input = new QLineEdit(frame);
        omega_vertical_input->setObjectName(QString::fromUtf8("omega_vertical_input"));
        omega_vertical_input->setEnabled(true);

        gridLayout->addWidget(omega_vertical_input, 4, 1, 1, 1, Qt::AlignmentFlag::AlignLeft);

        omega_vertical = new QLabel(frame);
        omega_vertical->setObjectName(QString::fromUtf8("omega_vertical"));

        gridLayout->addWidget(omega_vertical, 4, 0, 1, 1, Qt::AlignmentFlag::AlignRight);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        up_b = new QPushButton(frame);
        up_b->setObjectName(QString::fromUtf8("up_b"));
        sizePolicy1.setHeightForWidth(up_b->sizePolicy().hasHeightForWidth());
        up_b->setSizePolicy(sizePolicy1);
        up_b->setMinimumSize(QSize(0, 0));
        up_b->setSizeIncrement(QSize(0, 0));
        up_b->setBaseSize(QSize(0, 0));

        horizontalLayout_3->addWidget(up_b, 0, Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignBottom);

        up_2_b = new QPushButton(frame);
        up_2_b->setObjectName(QString::fromUtf8("up_2_b"));
        up_2_b->setMinimumSize(QSize(0, 0));
        up_2_b->setMaximumSize(QSize(16777215, 16777215));
        up_2_b->setStyleSheet(QString::fromUtf8("QPushButton:pressed{\n"
"	background-color:rgb(127,12,335);\n"
"	border:none;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(up_2_b, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignBottom);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        l_l = new QPushButton(frame);
        l_l->setObjectName(QString::fromUtf8("l_l"));
        l_l->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(l_l, 0, Qt::AlignmentFlag::AlignRight);

        l_2_b = new QPushButton(frame);
        l_2_b->setObjectName(QString::fromUtf8("l_2_b"));
        l_2_b->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(l_2_b, 0, Qt::AlignmentFlag::AlignRight);


        gridLayout_3->addLayout(verticalLayout_5, 2, 1, 1, 1);

        stop_b = new QPushButton(frame);
        stop_b->setObjectName(QString::fromUtf8("stop_b"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stop_b->sizePolicy().hasHeightForWidth());
        stop_b->setSizePolicy(sizePolicy4);
        stop_b->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(stop_b, 2, 2, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        r_b = new QPushButton(frame);
        r_b->setObjectName(QString::fromUtf8("r_b"));
        r_b->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(r_b, 0, Qt::AlignmentFlag::AlignLeft);

        r_2_b = new QPushButton(frame);
        r_2_b->setObjectName(QString::fromUtf8("r_2_b"));
        r_2_b->setMinimumSize(QSize(0, 0));

        verticalLayout_8->addWidget(r_2_b, 0, Qt::AlignmentFlag::AlignLeft);


        gridLayout_3->addLayout(verticalLayout_8, 2, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        d_2_b = new QPushButton(frame);
        d_2_b->setObjectName(QString::fromUtf8("d_2_b"));
        d_2_b->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(d_2_b, 0, Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop);

        d_b = new QPushButton(frame);
        d_b->setObjectName(QString::fromUtf8("d_b"));
        d_b->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(d_b, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 2, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_9->addWidget(label_2, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        mode_input = new QComboBox(frame);
        mode_input->addItem(QString());
        mode_input->addItem(QString());
        mode_input->addItem(QString());
        mode_input->addItem(QString());
        mode_input->setObjectName(QString::fromUtf8("mode_input"));

        gridLayout_9->addWidget(mode_input, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        gridLayout_3->addLayout(gridLayout_9, 1, 1, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_10->addWidget(label_7, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        step_input = new QComboBox(frame);
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->addItem(QString());
        step_input->setObjectName(QString::fromUtf8("step_input"));

        gridLayout_10->addWidget(step_input, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        gridLayout_3->addLayout(gridLayout_10, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


        gridLayout_2->addWidget(frame, 3, 4, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_12->addWidget(label_15, 0, 0, 1, 1, Qt::AlignmentFlag::AlignLeft);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_12->addWidget(label_8, 0, 2, 1, 1, Qt::AlignmentFlag::AlignRight);

        hor_out = new QLabel(centralwidget);
        hor_out->setObjectName(QString::fromUtf8("hor_out"));
        hor_out->setFont(font);

        gridLayout_12->addWidget(hor_out, 0, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        gridLayout_2->addLayout(gridLayout_12, 1, 1, 1, 1);

        status_label = new QLabel(centralwidget);
        status_label->setObjectName(QString::fromUtf8("status_label"));

        gridLayout_2->addWidget(status_label, 2, 4, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1950, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        videoLabel->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        vert_out->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "-20", nullptr));
        videoLabel2->setText(QString());
        l_vid_turn->setText(QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
        start_b->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stop_b_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        switch_vid->setText(QCoreApplication::translate("MainWindow", "Switch Videos", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Tracking", nullptr));
        break_range_b->setText(QCoreApplication::translate("MainWindow", "Break Range", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mesurement Mode", nullptr));
        pulse_b->setText(QCoreApplication::translate("MainWindow", "Pulse\n"
" ON", nullptr));
        temp_out->setText(QString());
        measure_mode->setItemText(0, QCoreApplication::translate("MainWindow", "SMM", nullptr));
        measure_mode->setItemText(1, QCoreApplication::translate("MainWindow", "CMM 1Hz", nullptr));
        measure_mode->setItemText(2, QCoreApplication::translate("MainWindow", "CMM 4Hz", nullptr));
        measure_mode->setItemText(3, QCoreApplication::translate("MainWindow", "CMM 10Hz", nullptr));
        measure_mode->setItemText(4, QCoreApplication::translate("MainWindow", "CMM 20Hz", nullptr));
        measure_mode->setItemText(5, QCoreApplication::translate("MainWindow", "CMM 100Hz", nullptr));
        measure_mode->setItemText(6, QCoreApplication::translate("MainWindow", "CMM 200Hz", nullptr));
        measure_mode->setItemText(7, QCoreApplication::translate("MainWindow", "Quick SMM 1", nullptr));
        measure_mode->setItemText(8, QCoreApplication::translate("MainWindow", "Quick SMM 2", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "pulse frequency", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Time remaining (sec)", nullptr));
        laser_act_b->setText(QCoreApplication::translate("MainWindow", "Laser \n"
"Activation", nullptr));
        error_label->setText(QCoreApplication::translate("MainWindow", "Error: NONE", nullptr));
        start_range_b->setText(QCoreApplication::translate("MainWindow", "Start Range", nullptr));
        time_remaining_out->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        pointer_b->setText(QCoreApplication::translate("MainWindow", "Pointer", nullptr));
        frequency_mode->setItemText(0, QCoreApplication::translate("MainWindow", "1 HZ", nullptr));
        frequency_mode->setItemText(1, QCoreApplication::translate("MainWindow", "2 Hz", nullptr));
        frequency_mode->setItemText(2, QCoreApplication::translate("MainWindow", "5 Hz", nullptr));
        frequency_mode->setItemText(3, QCoreApplication::translate("MainWindow", "10 Hz", nullptr));
        frequency_mode->setItemText(4, QCoreApplication::translate("MainWindow", "20 HZ", nullptr));
        frequency_mode->setItemText(5, QCoreApplication::translate("MainWindow", "25 HZ", nullptr));
        frequency_mode->setItemText(6, QCoreApplication::translate("MainWindow", "0,5 HZ", nullptr));
        frequency_mode->setItemText(7, QCoreApplication::translate("MainWindow", "0,1 HZ", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Temperature \302\260C", nullptr));
        ext_radiation_b->setText(QCoreApplication::translate("MainWindow", "External\n"
" Radiation", nullptr));
        term_control_b->setText(QCoreApplication::translate("MainWindow", "Thermal \n"
"Control", nullptr));
        get_frequency->setText(QCoreApplication::translate("MainWindow", "Get PRF Period", nullptr));
        third_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        third_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        third_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        third_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        third_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        third_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        third_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        third_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        second_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        second_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        second_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        second_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        second_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        second_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        second_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        second_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        first_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        first_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        first_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        first_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        first_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        first_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        first_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        first_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        get_stanag->setText(QCoreApplication::translate("MainWindow", "Set STANAG", nullptr));
        horizontal_mark->setText(QCoreApplication::translate("MainWindow", "Horizontal Marker", nullptr));
        omega_horizontal->setText(QCoreApplication::translate("MainWindow", "\317\211 H", nullptr));
        vertical_mark->setText(QCoreApplication::translate("MainWindow", "Vertical Marker", nullptr));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        mode_input->setItemText(0, QCoreApplication::translate("MainWindow", "INERT", nullptr));
        mode_input->setItemText(1, QCoreApplication::translate("MainWindow", "BODY", nullptr));
        mode_input->setItemText(2, QCoreApplication::translate("MainWindow", "EARTH", nullptr));
        mode_input->setItemText(3, QCoreApplication::translate("MainWindow", "TRACKING", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Step (\302\260/s)", nullptr));
        step_input->setItemText(0, QCoreApplication::translate("MainWindow", "0.001", nullptr));
        step_input->setItemText(1, QCoreApplication::translate("MainWindow", "0.01", nullptr));
        step_input->setItemText(2, QCoreApplication::translate("MainWindow", "0.035", nullptr));
        step_input->setItemText(3, QCoreApplication::translate("MainWindow", "0.05", nullptr));
        step_input->setItemText(4, QCoreApplication::translate("MainWindow", "0.1", nullptr));
        step_input->setItemText(5, QCoreApplication::translate("MainWindow", "0.5", nullptr));
        step_input->setItemText(6, QCoreApplication::translate("MainWindow", "1", nullptr));
        step_input->setItemText(7, QCoreApplication::translate("MainWindow", "2", nullptr));
        step_input->setItemText(8, QCoreApplication::translate("MainWindow", "3", nullptr));

        step_input->setCurrentText(QCoreApplication::translate("MainWindow", "0.001", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "-30", nullptr));
        hor_out->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        status_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
