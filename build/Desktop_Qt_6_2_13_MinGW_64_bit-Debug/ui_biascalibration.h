/********************************************************************************
** Form generated from reading UI file 'biascalibration.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIASCALIBRATION_H
#define UI_BIASCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BiasCalibration
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLineEdit *lineEditTime;
    QLabel *label_8;
    QLineEdit *lineEditOffset1;
    QLabel *label_11;
    QLineEdit *lineEditOffset2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QLabel *labelComment;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *lineEditBiasH;
    QLabel *label_2;
    QLineEdit *lineEditBiasV;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *setBiasButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *checkButton;
    QLabel *label_9;
    QLineEdit *lineEditBiasHVerify;
    QLabel *label_10;
    QLineEdit *lineEditBiasVVerify;

    void setupUi(QDialog *BiasCalibration)
    {
        if (BiasCalibration->objectName().isEmpty())
            BiasCalibration->setObjectName(QString::fromUtf8("BiasCalibration"));
        BiasCalibration->resize(677, 628);
        BiasCalibration->setStyleSheet(QString::fromUtf8("  QGroupBox {\n"
"        background: white;\n"
"        border-radius: 10px;\n"
"        margin-top: 10px;\n"
"        padding: 10px;\n"
"    }\n"
"QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    padding: 4px 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049; /* \320\242\321\200\320\276\321\205\320\270 \321\202\320\265\320\274\320\275\321\226\321\210\320\270\320\271 \320\267\320\265\320\273\320\265\320\275\320\270\320\271 */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #3e8e41; /* \320\251\320\265 \321\202\320\265\320\274\320\275\321\226\321\210\320\270\320\271 \320\267\320\265\320\273\320\265\320\275\320\270\320\271 */\n"
"    padding-top: 5px;\n"
"    padding-left: 9px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #4CAF50;\n"
"}"));
        verticalLayout = new QVBoxLayout(BiasCalibration);
        verticalLayout->setSpacing(27);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(BiasCalibration);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        formLayout->setHorizontalSpacing(20);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(12);
        label_7->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        lineEditTime = new QLineEdit(groupBox_2);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));
        lineEditTime->setFont(font);
        lineEditTime->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditTime);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        lineEditOffset1 = new QLineEdit(groupBox_2);
        lineEditOffset1->setObjectName(QString::fromUtf8("lineEditOffset1"));
        lineEditOffset1->setFont(font);
        lineEditOffset1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditOffset1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        lineEditOffset2 = new QLineEdit(groupBox_2);
        lineEditOffset2->setObjectName(QString::fromUtf8("lineEditOffset2"));
        lineEditOffset2->setFont(font);
        lineEditOffset2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditOffset2);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(BiasCalibration);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        groupBox_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        startButton = new QPushButton(groupBox_4);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        startButton->setFont(font1);
        startButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(startButton);

        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(24);

        horizontalLayout_3->addWidget(progressBar);

        labelComment = new QLabel(groupBox_4);
        labelComment->setObjectName(QString::fromUtf8("labelComment"));
        QFont font2;
        font2.setItalic(true);
        labelComment->setFont(font2);

        horizontalLayout_3->addWidget(labelComment);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(BiasCalibration);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        formLayout_2->setHorizontalSpacing(20);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lineEditBiasH = new QLineEdit(groupBox_3);
        lineEditBiasH->setObjectName(QString::fromUtf8("lineEditBiasH"));
        lineEditBiasH->setFont(font);
        lineEditBiasH->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));
        lineEditBiasH->setReadOnly(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditBiasH);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditBiasV = new QLineEdit(groupBox_3);
        lineEditBiasV->setObjectName(QString::fromUtf8("lineEditBiasV"));
        lineEditBiasV->setFont(font);
        lineEditBiasV->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));
        lineEditBiasV->setReadOnly(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditBiasV);


        verticalLayout_2->addLayout(formLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveButton = new QPushButton(groupBox_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font1);
        saveButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(saveButton);

        setBiasButton = new QPushButton(groupBox_3);
        setBiasButton->setObjectName(QString::fromUtf8("setBiasButton"));
        setBiasButton->setFont(font1);
        setBiasButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(setBiasButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(BiasCalibration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(24);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkButton = new QPushButton(groupBox);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setFont(font1);
        checkButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(checkButton);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_5->addWidget(label_9);

        lineEditBiasHVerify = new QLineEdit(groupBox);
        lineEditBiasHVerify->setObjectName(QString::fromUtf8("lineEditBiasHVerify"));
        lineEditBiasHVerify->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));
        lineEditBiasHVerify->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditBiasHVerify);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        horizontalLayout_5->addWidget(label_10);

        lineEditBiasVVerify = new QLineEdit(groupBox);
        lineEditBiasVVerify->setObjectName(QString::fromUtf8("lineEditBiasVVerify"));
        lineEditBiasVVerify->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"}"));
        lineEditBiasVVerify->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditBiasVVerify);


        verticalLayout->addWidget(groupBox);


        retranslateUi(BiasCalibration);

        QMetaObject::connectSlotsByName(BiasCalibration);
    } // setupUi

    void retranslateUi(QDialog *BiasCalibration)
    {
        BiasCalibration->setWindowTitle(QCoreApplication::translate("BiasCalibration", "Bias calibration", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("BiasCalibration", "Calibration Settings", nullptr));
        label_7->setText(QCoreApplication::translate("BiasCalibration", "Time, sec:", nullptr));
        lineEditTime->setText(QCoreApplication::translate("BiasCalibration", "30", nullptr));
        label_8->setText(QCoreApplication::translate("BiasCalibration", "\316\2241:", nullptr));
        lineEditOffset1->setText(QCoreApplication::translate("BiasCalibration", "-100", nullptr));
        label_11->setText(QCoreApplication::translate("BiasCalibration", "\316\2242:", nullptr));
        lineEditOffset2->setText(QCoreApplication::translate("BiasCalibration", "100", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("BiasCalibration", "Calibration Process", nullptr));
        startButton->setText(QCoreApplication::translate("BiasCalibration", "Start Calibration", nullptr));
        labelComment->setText(QCoreApplication::translate("BiasCalibration", "Comment", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("BiasCalibration", "Bias Adjustment", nullptr));
        label->setText(QCoreApplication::translate("BiasCalibration", "Horisontal Bias (H):", nullptr));
        lineEditBiasH->setText(QCoreApplication::translate("BiasCalibration", "0", nullptr));
        label_2->setText(QCoreApplication::translate("BiasCalibration", "Vertical Bias (V):", nullptr));
        lineEditBiasV->setText(QCoreApplication::translate("BiasCalibration", "0", nullptr));
        saveButton->setText(QCoreApplication::translate("BiasCalibration", "Save", nullptr));
        setBiasButton->setText(QCoreApplication::translate("BiasCalibration", "Set Bias", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BiasCalibration", "Verification", nullptr));
        checkButton->setText(QCoreApplication::translate("BiasCalibration", "Check", nullptr));
        label_9->setText(QCoreApplication::translate("BiasCalibration", "Bias (H):", nullptr));
        label_10->setText(QCoreApplication::translate("BiasCalibration", "Bias (V):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BiasCalibration: public Ui_BiasCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIASCALIBRATION_H
