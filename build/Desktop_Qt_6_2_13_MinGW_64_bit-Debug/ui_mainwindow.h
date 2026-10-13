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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickable.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSet_program_0;
    QAction *actionBias_calibration;
    QAction *actionZero_set_H;
    QAction *actionZero_set_V;
    QAction *actionZero_reset_H;
    QAction *actionZero_reset_V;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QSlider *verticalSlider;
    ClickableLabel *videoLabel;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QLabel *vert_out;
    QLabel *label_11;
    QGridLayout *gridLayout_12;
    QLabel *hor_out;
    QLabel *label_15;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *H_label;
    QLabel *V_label;
    QLabel *wH_label;
    QLabel *wV_label;
    QLabel *valueDacH_label;
    QLabel *valueDacV_label;
    QSlider *horizontalSlider;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *controlRowFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *statusRowFrame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *status_label;
    QLabel *rxLabel;
    QLabel *txLabel;
    QLabel *labelLaserStatus;
    QLabel *labelPlatformStatus;
    QFrame *controlsFrame;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupMode;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioModeInert;
    QRadioButton *radioModeBody;
    QRadioButton *radioModeTracking;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *stop_track;
    QFrame *secondaryVideoFrame;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxVideo;
    QHBoxLayout *horizontalLayout_4;
    ClickableLabel *videoLabel2;
    QPushButton *l_vid_turn;
    QFrame *laserControlFrame;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupLaserControl;
    QHBoxLayout *horizontalLayout_13;
    QFrame *mainControlsFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *laser_act_b;
    QPushButton *pulse_b;
    QToolButton *btnLaserAdvanced;
    QGridLayout *gridLayout_4;
    QLabel *labelLaserErrorValue;
    QLabel *labelLaserTempValue;
    QLabel *labelLaserErrorTitle;
    QLabel *labelLaserTempTitle;
    QLabel *labelPulseTimerTitle;
    QLabel *labelPulseTimerValue;
    QFrame *laserAdvancedFrame;
    QVBoxLayout *verticalLayout;
    QWidget *rowThermalWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *term_control_b;
    QPushButton *ext_radiation_b;
    QWidget *rowFreqWidget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *pulseFreqLabel;
    QComboBox *frequency_mode;
    QWidget *rowStanagWidget;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_stanag;
    QLabel *label_first_digit_stanag;
    QComboBox *first_STANAG;
    QComboBox *second_STANAG;
    QComboBox *third_STANAG;
    QPushButton *get_stanag;
    QWidget *rowPeriodWidget;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_period;
    QLineEdit *period_out;
    QLineEdit *frequency_out;
    QPushButton *get_frequency;
    QWidget *rowPwrWidget;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_energy;
    QRadioButton *energy_0;
    QRadioButton *energy_1;
    QRadioButton *energy_2;
    QRadioButton *energy_3;
    QRadioButton *energy_4;
    QRadioButton *energy_5;
    QGroupBox *groupLrfControl;
    QGridLayout *gridLayout_5;
    QComboBox *comboMeasurementMode;
    QPushButton *start_range_b;
    QLineEdit *range_out;
    QLabel *labelMeasurementMode;
    QPushButton *break_range_b;
    QPushButton *pointer_b;
    QLabel *labelDistanceTitle;
    QGroupBox *groupPlatformControl;
    QVBoxLayout *verticalLayout_9;
    QFrame *padsRowFrame;
    QHBoxLayout *horizontalLayout_8;
    QFrame *holdPadFrame;
    QGridLayout *gridLayout_8;
    QPushButton *stop_b;
    QLabel *labelHoldPad;
    QPushButton *d_2_b;
    QPushButton *r_2_b;
    QPushButton *up_2_b;
    QPushButton *l_2_b;
    QFrame *stepPadFrame;
    QGridLayout *gridLayout_9;
    QLabel *labelDot;
    QLabel *labelStepPad;
    QPushButton *d_b;
    QPushButton *up_b;
    QPushButton *r_b;
    QPushButton *l_l;
    QFrame *topRowFrame;
    QGridLayout *gridLayout_3;
    QComboBox *step_input;
    QLabel *label_step;
    QPushButton *zero_b;
    QMenuBar *menubar;
    QMenu *menuLPS_Control;
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
        actionSet_program_0 = new QAction(MainWindow);
        actionSet_program_0->setObjectName(QString::fromUtf8("actionSet_program_0"));
        actionBias_calibration = new QAction(MainWindow);
        actionBias_calibration->setObjectName(QString::fromUtf8("actionBias_calibration"));
        actionZero_set_H = new QAction(MainWindow);
        actionZero_set_H->setObjectName(QString::fromUtf8("actionZero_set_H"));
        actionZero_set_V = new QAction(MainWindow);
        actionZero_set_V->setObjectName(QString::fromUtf8("actionZero_set_V"));
        actionZero_reset_H = new QAction(MainWindow);
        actionZero_reset_H->setObjectName(QString::fromUtf8("actionZero_reset_H"));
        actionZero_reset_V = new QAction(MainWindow);
        actionZero_reset_V->setObjectName(QString::fromUtf8("actionZero_reset_V"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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

        gridLayout_2->addWidget(verticalSlider, 6, 1, 1, 1);

        videoLabel = new ClickableLabel(centralwidget);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(videoLabel->sizePolicy().hasHeightForWidth());
        videoLabel->setSizePolicy(sizePolicy);
        videoLabel->setMinimumSize(QSize(0, 0));
        videoLabel->setAutoFillBackground(false);
        videoLabel->setStyleSheet(QString::fromUtf8(""));
        videoLabel->setFrameShape(QFrame::Shape::NoFrame);

        gridLayout_2->addWidget(videoLabel, 6, 0, 1, 1);

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
        font.setPointSize(14);
        vert_out->setFont(font);

        verticalLayout_4->addWidget(vert_out, 0, Qt::AlignmentFlag::AlignVCenter);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11, 0, Qt::AlignmentFlag::AlignBottom);


        gridLayout_2->addLayout(verticalLayout_4, 6, 2, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        hor_out = new QLabel(centralwidget);
        hor_out->setObjectName(QString::fromUtf8("hor_out"));
        QFont font1;
        font1.setPointSize(17);
        hor_out->setFont(font1);
        hor_out->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        hor_out->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        gridLayout_12->addWidget(hor_out, 0, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_12->addWidget(label_15, 0, 0, 1, 1, Qt::AlignmentFlag::AlignLeft);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_12->addWidget(label_8, 0, 2, 1, 1, Qt::AlignmentFlag::AlignRight);


        gridLayout_2->addLayout(gridLayout_12, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        H_label = new QLabel(centralwidget);
        H_label->setObjectName(QString::fromUtf8("H_label"));
        H_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(H_label);

        V_label = new QLabel(centralwidget);
        V_label->setObjectName(QString::fromUtf8("V_label"));
        V_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 2px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(V_label);

        wH_label = new QLabel(centralwidget);
        wH_label->setObjectName(QString::fromUtf8("wH_label"));
        wH_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 6px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(wH_label);

        wV_label = new QLabel(centralwidget);
        wV_label->setObjectName(QString::fromUtf8("wV_label"));
        wV_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 6px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(wV_label);

        valueDacH_label = new QLabel(centralwidget);
        valueDacH_label->setObjectName(QString::fromUtf8("valueDacH_label"));
        valueDacH_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 6px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(valueDacH_label);

        valueDacV_label = new QLabel(centralwidget);
        valueDacV_label->setObjectName(QString::fromUtf8("valueDacV_label"));
        valueDacV_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Consolas;\n"
"    font-size: 12pt;\n"
"    color: black;\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    padding: 2px 6px;\n"
"    min-width: 70px;\n"
"    qproperty-alignment: 'AlignLeft | AlignVCenter';\n"
"}"));

        horizontalLayout_6->addWidget(valueDacV_label);


        gridLayout_2->addLayout(horizontalLayout_6, 5, 0, 1, 1);

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

        gridLayout_2->addWidget(horizontalSlider, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setMinimumSize(QSize(420, 0));
        frame_2->setMaximumSize(QSize(460, 16777215));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 0, 6, 0);
        controlRowFrame = new QFrame(frame_2);
        controlRowFrame->setObjectName(QString::fromUtf8("controlRowFrame"));
        controlRowFrame->setMinimumSize(QSize(0, 70));
        controlRowFrame->setMaximumSize(QSize(16777215, 100));
        controlRowFrame->setFrameShape(QFrame::Shape::StyledPanel);
        controlRowFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(controlRowFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 0, 6, 0);
        statusRowFrame = new QFrame(controlRowFrame);
        statusRowFrame->setObjectName(QString::fromUtf8("statusRowFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(statusRowFrame->sizePolicy().hasHeightForWidth());
        statusRowFrame->setSizePolicy(sizePolicy3);
        statusRowFrame->setMinimumSize(QSize(0, 0));
        statusRowFrame->setMaximumSize(QSize(16777215, 20));
        statusRowFrame->setFrameShape(QFrame::Shape::StyledPanel);
        statusRowFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(statusRowFrame);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, 0);
        status_label = new QLabel(statusRowFrame);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        sizePolicy3.setHeightForWidth(status_label->sizePolicy().hasHeightForWidth());
        status_label->setSizePolicy(sizePolicy3);
        status_label->setMinimumSize(QSize(100, 20));
        status_label->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setBold(true);
        status_label->setFont(font2);

        horizontalLayout_5->addWidget(status_label);

        rxLabel = new QLabel(statusRowFrame);
        rxLabel->setObjectName(QString::fromUtf8("rxLabel"));
        rxLabel->setMinimumSize(QSize(40, 20));
        rxLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(rxLabel);

        txLabel = new QLabel(statusRowFrame);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setMinimumSize(QSize(40, 20));
        txLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(txLabel);

        labelLaserStatus = new QLabel(statusRowFrame);
        labelLaserStatus->setObjectName(QString::fromUtf8("labelLaserStatus"));
        labelLaserStatus->setMinimumSize(QSize(60, 20));
        labelLaserStatus->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(labelLaserStatus);

        labelPlatformStatus = new QLabel(statusRowFrame);
        labelPlatformStatus->setObjectName(QString::fromUtf8("labelPlatformStatus"));
        labelPlatformStatus->setMinimumSize(QSize(50, 20));
        labelPlatformStatus->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_5->addWidget(labelPlatformStatus);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 1);

        verticalLayout_2->addWidget(statusRowFrame);

        controlsFrame = new QFrame(controlRowFrame);
        controlsFrame->setObjectName(QString::fromUtf8("controlsFrame"));
        controlsFrame->setMinimumSize(QSize(0, 0));
        controlsFrame->setMaximumSize(QSize(16777215, 50));
        controlsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        controlsFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(controlsFrame);
        horizontalLayout_7->setSpacing(4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        groupMode = new QGroupBox(controlsFrame);
        groupMode->setObjectName(QString::fromUtf8("groupMode"));
        groupMode->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(groupMode);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioModeInert = new QRadioButton(groupMode);
        radioModeInert->setObjectName(QString::fromUtf8("radioModeInert"));
        radioModeInert->setCheckable(true);
        radioModeInert->setChecked(false);

        horizontalLayout_3->addWidget(radioModeInert);

        radioModeBody = new QRadioButton(groupMode);
        radioModeBody->setObjectName(QString::fromUtf8("radioModeBody"));
        radioModeBody->setCheckable(true);

        horizontalLayout_3->addWidget(radioModeBody);

        radioModeTracking = new QRadioButton(groupMode);
        radioModeTracking->setObjectName(QString::fromUtf8("radioModeTracking"));

        horizontalLayout_3->addWidget(radioModeTracking);


        horizontalLayout_7->addWidget(groupMode);

        groupBox_2 = new QGroupBox(controlsFrame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, -1, 0);
        stop_track = new QPushButton(groupBox_2);
        stop_track->setObjectName(QString::fromUtf8("stop_track"));
        stop_track->setMinimumSize(QSize(0, 20));
        stop_track->setMaximumSize(QSize(100, 20));

        horizontalLayout_10->addWidget(stop_track);


        horizontalLayout_7->addWidget(groupBox_2);


        verticalLayout_2->addWidget(controlsFrame);


        verticalLayout_3->addWidget(controlRowFrame);

        secondaryVideoFrame = new QFrame(frame_2);
        secondaryVideoFrame->setObjectName(QString::fromUtf8("secondaryVideoFrame"));
        sizePolicy2.setHeightForWidth(secondaryVideoFrame->sizePolicy().hasHeightForWidth());
        secondaryVideoFrame->setSizePolicy(sizePolicy2);
        secondaryVideoFrame->setMinimumSize(QSize(0, 0));
        secondaryVideoFrame->setMaximumSize(QSize(16777215, 16777215));
        secondaryVideoFrame->setFrameShape(QFrame::Shape::StyledPanel);
        secondaryVideoFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(secondaryVideoFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBoxVideo = new QGroupBox(secondaryVideoFrame);
        groupBoxVideo->setObjectName(QString::fromUtf8("groupBoxVideo"));
        horizontalLayout_4 = new QHBoxLayout(groupBoxVideo);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        videoLabel2 = new ClickableLabel(groupBoxVideo);
        videoLabel2->setObjectName(QString::fromUtf8("videoLabel2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(videoLabel2->sizePolicy().hasHeightForWidth());
        videoLabel2->setSizePolicy(sizePolicy4);
        videoLabel2->setMinimumSize(QSize(240, 192));
        videoLabel2->setMaximumSize(QSize(400, 16777215));
        videoLabel2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(videoLabel2);

        l_vid_turn = new QPushButton(groupBoxVideo);
        l_vid_turn->setObjectName(QString::fromUtf8("l_vid_turn"));
        l_vid_turn->setMinimumSize(QSize(50, 50));
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

        horizontalLayout_4->addWidget(l_vid_turn);


        horizontalLayout_2->addWidget(groupBoxVideo);


        verticalLayout_3->addWidget(secondaryVideoFrame);

        laserControlFrame = new QFrame(frame_2);
        laserControlFrame->setObjectName(QString::fromUtf8("laserControlFrame"));
        laserControlFrame->setFrameShape(QFrame::Shape::NoFrame);
        laserControlFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(laserControlFrame);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupLaserControl = new QGroupBox(laserControlFrame);
        groupLaserControl->setObjectName(QString::fromUtf8("groupLaserControl"));
        groupLaserControl->setMinimumSize(QSize(0, 120));
        groupLaserControl->setMaximumSize(QSize(16777215, 160));
        horizontalLayout_13 = new QHBoxLayout(groupLaserControl);
        horizontalLayout_13->setSpacing(4);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(4, 0, 4, 0);
        mainControlsFrame = new QFrame(groupLaserControl);
        mainControlsFrame->setObjectName(QString::fromUtf8("mainControlsFrame"));
        mainControlsFrame->setMinimumSize(QSize(0, 50));
        mainControlsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        mainControlsFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(mainControlsFrame);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 0, 4, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        laser_act_b = new QPushButton(mainControlsFrame);
        laser_act_b->setObjectName(QString::fromUtf8("laser_act_b"));
        laser_act_b->setEnabled(true);
        sizePolicy3.setHeightForWidth(laser_act_b->sizePolicy().hasHeightForWidth());
        laser_act_b->setSizePolicy(sizePolicy3);
        laser_act_b->setMinimumSize(QSize(0, 28));
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
        laser_act_b->setCheckable(false);
        laser_act_b->setFlat(false);

        horizontalLayout_11->addWidget(laser_act_b);

        pulse_b = new QPushButton(mainControlsFrame);
        pulse_b->setObjectName(QString::fromUtf8("pulse_b"));
        pulse_b->setEnabled(true);
        sizePolicy3.setHeightForWidth(pulse_b->sizePolicy().hasHeightForWidth());
        pulse_b->setSizePolicy(sizePolicy3);
        pulse_b->setMinimumSize(QSize(0, 28));
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

        horizontalLayout_11->addWidget(pulse_b);


        gridLayout->addLayout(horizontalLayout_11, 0, 0, 1, 2);

        btnLaserAdvanced = new QToolButton(mainControlsFrame);
        btnLaserAdvanced->setObjectName(QString::fromUtf8("btnLaserAdvanced"));
        sizePolicy3.setHeightForWidth(btnLaserAdvanced->sizePolicy().hasHeightForWidth());
        btnLaserAdvanced->setSizePolicy(sizePolicy3);
        btnLaserAdvanced->setMinimumSize(QSize(20, 20));
        btnLaserAdvanced->setMaximumSize(QSize(120, 16777215));
        btnLaserAdvanced->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);

        gridLayout->addWidget(btnLaserAdvanced, 5, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(16);
        gridLayout_4->setVerticalSpacing(4);
        labelLaserErrorValue = new QLabel(mainControlsFrame);
        labelLaserErrorValue->setObjectName(QString::fromUtf8("labelLaserErrorValue"));
        labelLaserErrorValue->setMinimumSize(QSize(70, 20));
        QFont font3;
        font3.setPointSize(9);
        labelLaserErrorValue->setFont(font3);

        gridLayout_4->addWidget(labelLaserErrorValue, 1, 1, 1, 1);

        labelLaserTempValue = new QLabel(mainControlsFrame);
        labelLaserTempValue->setObjectName(QString::fromUtf8("labelLaserTempValue"));
        labelLaserTempValue->setMinimumSize(QSize(70, 20));
        labelLaserTempValue->setFont(font3);

        gridLayout_4->addWidget(labelLaserTempValue, 0, 1, 1, 1);

        labelLaserErrorTitle = new QLabel(mainControlsFrame);
        labelLaserErrorTitle->setObjectName(QString::fromUtf8("labelLaserErrorTitle"));
        labelLaserErrorTitle->setMinimumSize(QSize(80, 20));
        labelLaserErrorTitle->setMaximumSize(QSize(86, 16777215));

        gridLayout_4->addWidget(labelLaserErrorTitle, 1, 0, 1, 1);

        labelLaserTempTitle = new QLabel(mainControlsFrame);
        labelLaserTempTitle->setObjectName(QString::fromUtf8("labelLaserTempTitle"));
        labelLaserTempTitle->setMinimumSize(QSize(80, 20));
        labelLaserTempTitle->setMaximumSize(QSize(86, 16777215));

        gridLayout_4->addWidget(labelLaserTempTitle, 0, 0, 1, 1);

        labelPulseTimerTitle = new QLabel(mainControlsFrame);
        labelPulseTimerTitle->setObjectName(QString::fromUtf8("labelPulseTimerTitle"));
        labelPulseTimerTitle->setMinimumSize(QSize(80, 20));
        labelPulseTimerTitle->setMaximumSize(QSize(86, 16777215));

        gridLayout_4->addWidget(labelPulseTimerTitle, 2, 0, 1, 1);

        labelPulseTimerValue = new QLabel(mainControlsFrame);
        labelPulseTimerValue->setObjectName(QString::fromUtf8("labelPulseTimerValue"));
        labelPulseTimerValue->setMinimumSize(QSize(70, 20));
        labelPulseTimerValue->setFont(font3);

        gridLayout_4->addWidget(labelPulseTimerValue, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 1, 0, 1, 2);


        horizontalLayout_13->addWidget(mainControlsFrame);

        laserAdvancedFrame = new QFrame(groupLaserControl);
        laserAdvancedFrame->setObjectName(QString::fromUtf8("laserAdvancedFrame"));
        laserAdvancedFrame->setFrameShape(QFrame::Shape::StyledPanel);
        laserAdvancedFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(laserAdvancedFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 0, 4, 0);
        rowThermalWidget = new QWidget(laserAdvancedFrame);
        rowThermalWidget->setObjectName(QString::fromUtf8("rowThermalWidget"));
        horizontalLayout_9 = new QHBoxLayout(rowThermalWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        term_control_b = new QPushButton(rowThermalWidget);
        term_control_b->setObjectName(QString::fromUtf8("term_control_b"));
        term_control_b->setEnabled(true);
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

        horizontalLayout_9->addWidget(term_control_b);

        ext_radiation_b = new QPushButton(rowThermalWidget);
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

        horizontalLayout_9->addWidget(ext_radiation_b);


        verticalLayout->addWidget(rowThermalWidget);

        rowFreqWidget = new QWidget(laserAdvancedFrame);
        rowFreqWidget->setObjectName(QString::fromUtf8("rowFreqWidget"));
        horizontalLayout_12 = new QHBoxLayout(rowFreqWidget);
        horizontalLayout_12->setSpacing(4);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        pulseFreqLabel = new QLabel(rowFreqWidget);
        pulseFreqLabel->setObjectName(QString::fromUtf8("pulseFreqLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pulseFreqLabel->sizePolicy().hasHeightForWidth());
        pulseFreqLabel->setSizePolicy(sizePolicy5);
        pulseFreqLabel->setMinimumSize(QSize(58, 0));

        horizontalLayout_12->addWidget(pulseFreqLabel);

        frequency_mode = new QComboBox(rowFreqWidget);
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

        horizontalLayout_12->addWidget(frequency_mode);


        verticalLayout->addWidget(rowFreqWidget);

        rowStanagWidget = new QWidget(laserAdvancedFrame);
        rowStanagWidget->setObjectName(QString::fromUtf8("rowStanagWidget"));
        horizontalLayout_14 = new QHBoxLayout(rowStanagWidget);
        horizontalLayout_14->setSpacing(4);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_stanag = new QLabel(rowStanagWidget);
        label_stanag->setObjectName(QString::fromUtf8("label_stanag"));
        sizePolicy5.setHeightForWidth(label_stanag->sizePolicy().hasHeightForWidth());
        label_stanag->setSizePolicy(sizePolicy5);
        label_stanag->setMinimumSize(QSize(58, 0));

        horizontalLayout_14->addWidget(label_stanag);

        label_first_digit_stanag = new QLabel(rowStanagWidget);
        label_first_digit_stanag->setObjectName(QString::fromUtf8("label_first_digit_stanag"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_first_digit_stanag->sizePolicy().hasHeightForWidth());
        label_first_digit_stanag->setSizePolicy(sizePolicy6);
        label_first_digit_stanag->setMaximumSize(QSize(10, 16777215));
        label_first_digit_stanag->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_14->addWidget(label_first_digit_stanag);

        first_STANAG = new QComboBox(rowStanagWidget);
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->addItem(QString());
        first_STANAG->setObjectName(QString::fromUtf8("first_STANAG"));
        first_STANAG->setMinimumSize(QSize(30, 0));
        first_STANAG->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(first_STANAG);

        second_STANAG = new QComboBox(rowStanagWidget);
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->addItem(QString());
        second_STANAG->setObjectName(QString::fromUtf8("second_STANAG"));
        second_STANAG->setMinimumSize(QSize(30, 0));
        second_STANAG->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(second_STANAG);

        third_STANAG = new QComboBox(rowStanagWidget);
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->addItem(QString());
        third_STANAG->setObjectName(QString::fromUtf8("third_STANAG"));
        third_STANAG->setMinimumSize(QSize(30, 0));
        third_STANAG->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(third_STANAG);

        get_stanag = new QPushButton(rowStanagWidget);
        get_stanag->setObjectName(QString::fromUtf8("get_stanag"));
        get_stanag->setMinimumSize(QSize(35, 24));
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

        horizontalLayout_14->addWidget(get_stanag);


        verticalLayout->addWidget(rowStanagWidget);

        rowPeriodWidget = new QWidget(laserAdvancedFrame);
        rowPeriodWidget->setObjectName(QString::fromUtf8("rowPeriodWidget"));
        horizontalLayout_15 = new QHBoxLayout(rowPeriodWidget);
        horizontalLayout_15->setSpacing(4);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_period = new QLabel(rowPeriodWidget);
        label_period->setObjectName(QString::fromUtf8("label_period"));
        sizePolicy5.setHeightForWidth(label_period->sizePolicy().hasHeightForWidth());
        label_period->setSizePolicy(sizePolicy5);
        label_period->setMinimumSize(QSize(58, 0));

        horizontalLayout_15->addWidget(label_period);

        period_out = new QLineEdit(rowPeriodWidget);
        period_out->setObjectName(QString::fromUtf8("period_out"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(period_out->sizePolicy().hasHeightForWidth());
        period_out->setSizePolicy(sizePolicy7);
        period_out->setMinimumSize(QSize(52, 0));

        horizontalLayout_15->addWidget(period_out);

        frequency_out = new QLineEdit(rowPeriodWidget);
        frequency_out->setObjectName(QString::fromUtf8("frequency_out"));
        sizePolicy7.setHeightForWidth(frequency_out->sizePolicy().hasHeightForWidth());
        frequency_out->setSizePolicy(sizePolicy7);
        frequency_out->setMinimumSize(QSize(52, 0));

        horizontalLayout_15->addWidget(frequency_out);

        get_frequency = new QPushButton(rowPeriodWidget);
        get_frequency->setObjectName(QString::fromUtf8("get_frequency"));
        get_frequency->setMinimumSize(QSize(35, 24));
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

        horizontalLayout_15->addWidget(get_frequency);


        verticalLayout->addWidget(rowPeriodWidget);

        rowPwrWidget = new QWidget(laserAdvancedFrame);
        rowPwrWidget->setObjectName(QString::fromUtf8("rowPwrWidget"));
        horizontalLayout_16 = new QHBoxLayout(rowPwrWidget);
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_energy = new QLabel(rowPwrWidget);
        label_energy->setObjectName(QString::fromUtf8("label_energy"));
        sizePolicy5.setHeightForWidth(label_energy->sizePolicy().hasHeightForWidth());
        label_energy->setSizePolicy(sizePolicy5);
        label_energy->setMinimumSize(QSize(58, 0));

        horizontalLayout_16->addWidget(label_energy);

        energy_0 = new QRadioButton(rowPwrWidget);
        energy_0->setObjectName(QString::fromUtf8("energy_0"));

        horizontalLayout_16->addWidget(energy_0);

        energy_1 = new QRadioButton(rowPwrWidget);
        energy_1->setObjectName(QString::fromUtf8("energy_1"));

        horizontalLayout_16->addWidget(energy_1);

        energy_2 = new QRadioButton(rowPwrWidget);
        energy_2->setObjectName(QString::fromUtf8("energy_2"));

        horizontalLayout_16->addWidget(energy_2);

        energy_3 = new QRadioButton(rowPwrWidget);
        energy_3->setObjectName(QString::fromUtf8("energy_3"));

        horizontalLayout_16->addWidget(energy_3);

        energy_4 = new QRadioButton(rowPwrWidget);
        energy_4->setObjectName(QString::fromUtf8("energy_4"));

        horizontalLayout_16->addWidget(energy_4);

        energy_5 = new QRadioButton(rowPwrWidget);
        energy_5->setObjectName(QString::fromUtf8("energy_5"));

        horizontalLayout_16->addWidget(energy_5);


        verticalLayout->addWidget(rowPwrWidget);


        horizontalLayout_13->addWidget(laserAdvancedFrame);


        verticalLayout_6->addWidget(groupLaserControl);

        groupLrfControl = new QGroupBox(laserControlFrame);
        groupLrfControl->setObjectName(QString::fromUtf8("groupLrfControl"));
        groupLrfControl->setMinimumSize(QSize(0, 90));
        groupLrfControl->setMaximumSize(QSize(16777215, 130));
        gridLayout_5 = new QGridLayout(groupLrfControl);
        gridLayout_5->setSpacing(4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(6, 6, 6, 6);
        comboMeasurementMode = new QComboBox(groupLrfControl);
        comboMeasurementMode->addItem(QString());
        comboMeasurementMode->addItem(QString());
        comboMeasurementMode->addItem(QString());
        comboMeasurementMode->addItem(QString());
        comboMeasurementMode->setObjectName(QString::fromUtf8("comboMeasurementMode"));
        sizePolicy3.setHeightForWidth(comboMeasurementMode->sizePolicy().hasHeightForWidth());
        comboMeasurementMode->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(comboMeasurementMode, 0, 1, 1, 1);

        start_range_b = new QPushButton(groupLrfControl);
        start_range_b->setObjectName(QString::fromUtf8("start_range_b"));
        sizePolicy6.setHeightForWidth(start_range_b->sizePolicy().hasHeightForWidth());
        start_range_b->setSizePolicy(sizePolicy6);
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

        gridLayout_5->addWidget(start_range_b, 1, 0, 1, 1);

        range_out = new QLineEdit(groupLrfControl);
        range_out->setObjectName(QString::fromUtf8("range_out"));
        sizePolicy3.setHeightForWidth(range_out->sizePolicy().hasHeightForWidth());
        range_out->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        range_out->setFont(font4);

        gridLayout_5->addWidget(range_out, 2, 1, 1, 1);

        labelMeasurementMode = new QLabel(groupLrfControl);
        labelMeasurementMode->setObjectName(QString::fromUtf8("labelMeasurementMode"));

        gridLayout_5->addWidget(labelMeasurementMode, 0, 0, 1, 1);

        break_range_b = new QPushButton(groupLrfControl);
        break_range_b->setObjectName(QString::fromUtf8("break_range_b"));
        sizePolicy6.setHeightForWidth(break_range_b->sizePolicy().hasHeightForWidth());
        break_range_b->setSizePolicy(sizePolicy6);
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

        gridLayout_5->addWidget(break_range_b, 1, 1, 1, 1);

        pointer_b = new QPushButton(groupLrfControl);
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

        gridLayout_5->addWidget(pointer_b, 1, 2, 1, 1);

        labelDistanceTitle = new QLabel(groupLrfControl);
        labelDistanceTitle->setObjectName(QString::fromUtf8("labelDistanceTitle"));

        gridLayout_5->addWidget(labelDistanceTitle, 2, 0, 1, 1);


        verticalLayout_6->addWidget(groupLrfControl);

        groupPlatformControl = new QGroupBox(laserControlFrame);
        groupPlatformControl->setObjectName(QString::fromUtf8("groupPlatformControl"));
        groupPlatformControl->setMinimumSize(QSize(0, 100));
        verticalLayout_9 = new QVBoxLayout(groupPlatformControl);
        verticalLayout_9->setSpacing(4);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(6, 6, 6, 6);
        padsRowFrame = new QFrame(groupPlatformControl);
        padsRowFrame->setObjectName(QString::fromUtf8("padsRowFrame"));
        padsRowFrame->setMinimumSize(QSize(0, 50));
        padsRowFrame->setFrameShape(QFrame::Shape::StyledPanel);
        padsRowFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_8 = new QHBoxLayout(padsRowFrame);
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        holdPadFrame = new QFrame(padsRowFrame);
        holdPadFrame->setObjectName(QString::fromUtf8("holdPadFrame"));
        holdPadFrame->setMinimumSize(QSize(92, 0));
        holdPadFrame->setMaximumSize(QSize(100, 16777215));
        holdPadFrame->setFrameShape(QFrame::Shape::NoFrame);
        holdPadFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_8 = new QGridLayout(holdPadFrame);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(0);
        gridLayout_8->setVerticalSpacing(2);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        stop_b = new QPushButton(holdPadFrame);
        stop_b->setObjectName(QString::fromUtf8("stop_b"));
        stop_b->setMinimumSize(QSize(40, 26));
        stop_b->setMaximumSize(QSize(40, 28));

        gridLayout_8->addWidget(stop_b, 2, 1, 1, 1);

        labelHoldPad = new QLabel(holdPadFrame);
        labelHoldPad->setObjectName(QString::fromUtf8("labelHoldPad"));
        labelHoldPad->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(labelHoldPad, 1, 0, 1, 1);

        d_2_b = new QPushButton(holdPadFrame);
        d_2_b->setObjectName(QString::fromUtf8("d_2_b"));
        d_2_b->setMinimumSize(QSize(24, 24));
        d_2_b->setMaximumSize(QSize(28, 28));

        gridLayout_8->addWidget(d_2_b, 3, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        r_2_b = new QPushButton(holdPadFrame);
        r_2_b->setObjectName(QString::fromUtf8("r_2_b"));
        r_2_b->setMinimumSize(QSize(24, 24));
        r_2_b->setMaximumSize(QSize(28, 28));

        gridLayout_8->addWidget(r_2_b, 2, 2, 1, 1);

        up_2_b = new QPushButton(holdPadFrame);
        up_2_b->setObjectName(QString::fromUtf8("up_2_b"));
        up_2_b->setMinimumSize(QSize(24, 24));
        up_2_b->setMaximumSize(QSize(28, 28));
        up_2_b->setStyleSheet(QString::fromUtf8("QPushButton:pressed{\n"
"	background-color:rgb(127,12,335);\n"
"	border:none;\n"
"}\n"
""));

        gridLayout_8->addWidget(up_2_b, 1, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        l_2_b = new QPushButton(holdPadFrame);
        l_2_b->setObjectName(QString::fromUtf8("l_2_b"));
        l_2_b->setMinimumSize(QSize(24, 24));
        l_2_b->setMaximumSize(QSize(28, 28));

        gridLayout_8->addWidget(l_2_b, 2, 0, 1, 1);

        gridLayout_8->setColumnStretch(0, 1);

        horizontalLayout_8->addWidget(holdPadFrame, 0, Qt::AlignmentFlag::AlignHCenter);

        stepPadFrame = new QFrame(padsRowFrame);
        stepPadFrame->setObjectName(QString::fromUtf8("stepPadFrame"));
        stepPadFrame->setMinimumSize(QSize(92, 0));
        stepPadFrame->setMaximumSize(QSize(100, 16777215));
        stepPadFrame->setFrameShape(QFrame::Shape::NoFrame);
        stepPadFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_9 = new QGridLayout(stepPadFrame);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setHorizontalSpacing(0);
        gridLayout_9->setVerticalSpacing(2);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        labelDot = new QLabel(stepPadFrame);
        labelDot->setObjectName(QString::fromUtf8("labelDot"));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        labelDot->setFont(font5);
        labelDot->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(labelDot, 2, 1, 1, 1);

        labelStepPad = new QLabel(stepPadFrame);
        labelStepPad->setObjectName(QString::fromUtf8("labelStepPad"));
        labelStepPad->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(labelStepPad, 1, 0, 1, 1);

        d_b = new QPushButton(stepPadFrame);
        d_b->setObjectName(QString::fromUtf8("d_b"));
        d_b->setMinimumSize(QSize(24, 24));
        d_b->setMaximumSize(QSize(28, 28));

        gridLayout_9->addWidget(d_b, 3, 1, 1, 1);

        up_b = new QPushButton(stepPadFrame);
        up_b->setObjectName(QString::fromUtf8("up_b"));
        sizePolicy5.setHeightForWidth(up_b->sizePolicy().hasHeightForWidth());
        up_b->setSizePolicy(sizePolicy5);
        up_b->setMinimumSize(QSize(24, 24));
        up_b->setMaximumSize(QSize(28, 28));
        up_b->setSizeIncrement(QSize(0, 0));
        up_b->setBaseSize(QSize(0, 0));
        up_b->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout_9->addWidget(up_b, 1, 1, 1, 1);

        r_b = new QPushButton(stepPadFrame);
        r_b->setObjectName(QString::fromUtf8("r_b"));
        r_b->setMinimumSize(QSize(24, 24));
        r_b->setMaximumSize(QSize(28, 28));

        gridLayout_9->addWidget(r_b, 2, 2, 1, 1);

        l_l = new QPushButton(stepPadFrame);
        l_l->setObjectName(QString::fromUtf8("l_l"));
        l_l->setMinimumSize(QSize(24, 24));
        l_l->setMaximumSize(QSize(28, 28));

        gridLayout_9->addWidget(l_l, 2, 0, 1, 1);


        horizontalLayout_8->addWidget(stepPadFrame, 0, Qt::AlignmentFlag::AlignHCenter);

        topRowFrame = new QFrame(padsRowFrame);
        topRowFrame->setObjectName(QString::fromUtf8("topRowFrame"));
        topRowFrame->setFrameShape(QFrame::Shape::StyledPanel);
        topRowFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(topRowFrame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        step_input = new QComboBox(topRowFrame);
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
        sizePolicy3.setHeightForWidth(step_input->sizePolicy().hasHeightForWidth());
        step_input->setSizePolicy(sizePolicy3);
        step_input->setMinimumSize(QSize(0, 24));
        step_input->setSizeIncrement(QSize(0, 28));

        gridLayout_3->addWidget(step_input, 0, 2, 1, 1);

        label_step = new QLabel(topRowFrame);
        label_step->setObjectName(QString::fromUtf8("label_step"));
        sizePolicy3.setHeightForWidth(label_step->sizePolicy().hasHeightForWidth());
        label_step->setSizePolicy(sizePolicy3);
        label_step->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(label_step, 0, 1, 1, 1);

        zero_b = new QPushButton(topRowFrame);
        zero_b->setObjectName(QString::fromUtf8("zero_b"));
        sizePolicy3.setHeightForWidth(zero_b->sizePolicy().hasHeightForWidth());
        zero_b->setSizePolicy(sizePolicy3);
        zero_b->setMinimumSize(QSize(0, 0));
        zero_b->setMaximumSize(QSize(16777215, 16777215));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        zero_b->setFont(font6);
        zero_b->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout_3->addWidget(zero_b, 1, 1, 1, 2);


        horizontalLayout_8->addWidget(topRowFrame);


        verticalLayout_9->addWidget(padsRowFrame);


        verticalLayout_6->addWidget(groupPlatformControl);


        verticalLayout_3->addWidget(laserControlFrame);


        horizontalLayout->addWidget(frame_2);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1950, 22));
        menuLPS_Control = new QMenu(menubar);
        menuLPS_Control->setObjectName(QString::fromUtf8("menuLPS_Control"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLPS_Control->menuAction());
        menuLPS_Control->addAction(actionSet_program_0);
        menuLPS_Control->addAction(actionBias_calibration);
        menuLPS_Control->addAction(actionZero_set_H);
        menuLPS_Control->addAction(actionZero_set_V);
        menuLPS_Control->addAction(actionZero_reset_H);
        menuLPS_Control->addAction(actionZero_reset_V);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LPS Control", nullptr));
        actionSet_program_0->setText(QCoreApplication::translate("MainWindow", "Set program 0", nullptr));
        actionBias_calibration->setText(QCoreApplication::translate("MainWindow", "Bias calibration", nullptr));
        actionZero_set_H->setText(QCoreApplication::translate("MainWindow", "Zero set (H)", nullptr));
        actionZero_set_V->setText(QCoreApplication::translate("MainWindow", "Zero set (V)", nullptr));
        actionZero_reset_H->setText(QCoreApplication::translate("MainWindow", "Zero reset (H)", nullptr));
        actionZero_reset_V->setText(QCoreApplication::translate("MainWindow", "Zero reset (V)", nullptr));
        videoLabel->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        vert_out->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "-20", nullptr));
        hor_out->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "-30", nullptr));
        H_label->setText(QCoreApplication::translate("MainWindow", "H:", nullptr));
        V_label->setText(QCoreApplication::translate("MainWindow", "V:", nullptr));
        wH_label->setText(QCoreApplication::translate("MainWindow", "wH:", nullptr));
        wV_label->setText(QCoreApplication::translate("MainWindow", "wV:", nullptr));
        valueDacH_label->setText(QCoreApplication::translate("MainWindow", "DacH:", nullptr));
        valueDacV_label->setText(QCoreApplication::translate("MainWindow", "DacV:", nullptr));
        status_label->setText(QCoreApplication::translate("MainWindow", "MODE: --", nullptr));
        rxLabel->setText(QCoreApplication::translate("MainWindow", "RX: OFF", nullptr));
        txLabel->setText(QCoreApplication::translate("MainWindow", "TX: OFF", nullptr));
        labelLaserStatus->setText(QCoreApplication::translate("MainWindow", "LASER: OFF", nullptr));
        labelPlatformStatus->setText(QCoreApplication::translate("MainWindow", "PLT: OFF", nullptr));
        groupMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        radioModeInert->setText(QCoreApplication::translate("MainWindow", "INERT", nullptr));
        radioModeBody->setText(QCoreApplication::translate("MainWindow", "BODY", nullptr));
        radioModeTracking->setText(QCoreApplication::translate("MainWindow", "TRACK", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Tracking", nullptr));
        stop_track->setText(QCoreApplication::translate("MainWindow", "Stop Track", nullptr));
        groupBoxVideo->setTitle(QCoreApplication::translate("MainWindow", "Video", nullptr));
        videoLabel2->setText(QString());
        l_vid_turn->setText(QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
        groupLaserControl->setTitle(QCoreApplication::translate("MainWindow", "Laser Control", nullptr));
        laser_act_b->setText(QCoreApplication::translate("MainWindow", "Laser Activation", nullptr));
        pulse_b->setText(QCoreApplication::translate("MainWindow", "Pulse ON", nullptr));
        btnLaserAdvanced->setText(QCoreApplication::translate("MainWindow", "Advanced \342\226\270", nullptr));
        labelLaserErrorValue->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
        labelLaserTempValue->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        labelLaserErrorTitle->setText(QCoreApplication::translate("MainWindow", "Error", nullptr));
        labelLaserTempTitle->setText(QCoreApplication::translate("MainWindow", "Temp \302\260C", nullptr));
        labelPulseTimerTitle->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        labelPulseTimerValue->setText(QCoreApplication::translate("MainWindow", "60 s", nullptr));
        term_control_b->setText(QCoreApplication::translate("MainWindow", "Thermal Control", nullptr));
        ext_radiation_b->setText(QCoreApplication::translate("MainWindow", "Shutter", nullptr));
        pulseFreqLabel->setText(QCoreApplication::translate("MainWindow", "Pulse Freq", nullptr));
        frequency_mode->setItemText(0, QCoreApplication::translate("MainWindow", "1 HZ", nullptr));
        frequency_mode->setItemText(1, QCoreApplication::translate("MainWindow", "2 Hz", nullptr));
        frequency_mode->setItemText(2, QCoreApplication::translate("MainWindow", "5 Hz", nullptr));
        frequency_mode->setItemText(3, QCoreApplication::translate("MainWindow", "10 Hz", nullptr));
        frequency_mode->setItemText(4, QCoreApplication::translate("MainWindow", "20 HZ", nullptr));
        frequency_mode->setItemText(5, QCoreApplication::translate("MainWindow", "25 HZ", nullptr));
        frequency_mode->setItemText(6, QCoreApplication::translate("MainWindow", "0,5 HZ", nullptr));
        frequency_mode->setItemText(7, QCoreApplication::translate("MainWindow", "0,2 HZ", nullptr));

        label_stanag->setText(QCoreApplication::translate("MainWindow", "STANAG", nullptr));
        label_first_digit_stanag->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        first_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        first_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        first_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        first_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        first_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        first_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        first_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        first_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        second_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        second_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        second_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        second_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        second_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        second_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        second_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        second_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        third_STANAG->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        third_STANAG->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        third_STANAG->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        third_STANAG->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        third_STANAG->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        third_STANAG->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        third_STANAG->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        third_STANAG->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        get_stanag->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_period->setText(QCoreApplication::translate("MainWindow", "Period | Hz", nullptr));
        get_frequency->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        label_energy->setText(QCoreApplication::translate("MainWindow", "Pwr", nullptr));
        energy_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        energy_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        energy_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        energy_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        energy_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        energy_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        groupLrfControl->setTitle(QCoreApplication::translate("MainWindow", "Rangefinder Control", nullptr));
        comboMeasurementMode->setItemText(0, QCoreApplication::translate("MainWindow", "SMM", nullptr));
        comboMeasurementMode->setItemText(1, QCoreApplication::translate("MainWindow", "CMM 1Hz", nullptr));
        comboMeasurementMode->setItemText(2, QCoreApplication::translate("MainWindow", "CMM 4Hz", nullptr));
        comboMeasurementMode->setItemText(3, QCoreApplication::translate("MainWindow", "CMM 10Hz", nullptr));

        start_range_b->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        range_out->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        labelMeasurementMode->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        break_range_b->setText(QCoreApplication::translate("MainWindow", "Break", nullptr));
        pointer_b->setText(QCoreApplication::translate("MainWindow", "Pointer", nullptr));
        labelDistanceTitle->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        groupPlatformControl->setTitle(QCoreApplication::translate("MainWindow", "Platform Control", nullptr));
        stop_b->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        labelHoldPad->setText(QCoreApplication::translate("MainWindow", "Hold", nullptr));
        d_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\212", nullptr));
        r_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\211", nullptr));
        up_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\210", nullptr));
        l_2_b->setText(QCoreApplication::translate("MainWindow", "\342\207\207", nullptr));
        labelDot->setText(QCoreApplication::translate("MainWindow", "\342\200\242", nullptr));
        labelStepPad->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        d_b->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        up_b->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        r_b->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        l_l->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
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
        label_step->setText(QCoreApplication::translate("MainWindow", "Step (\302\260/s)", nullptr));
        zero_b->setText(QCoreApplication::translate("MainWindow", "ZERO", nullptr));
        menuLPS_Control->setTitle(QCoreApplication::translate("MainWindow", "LPS Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
