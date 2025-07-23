#ifndef BIASCALIBRATION_H
#define BIASCALIBRATION_H

#include <QDialog>

namespace Ui {
class BiasCalibration;
}

class BiasCalibration : public QDialog
{
    Q_OBJECT

public:
    explicit BiasCalibration(QWidget *parent = nullptr);
    ~BiasCalibration();

private:
    Ui::BiasCalibration *ui;
};

#endif // BIASCALIBRATION_H
