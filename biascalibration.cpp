#include "biascalibration.h"
#include "ui_biascalibration.h"

BiasCalibration::BiasCalibration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BiasCalibration)
{
    ui->setupUi(this);
}

BiasCalibration::~BiasCalibration()
{
    delete ui;
}
