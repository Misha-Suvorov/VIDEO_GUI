// ClickableLabel.h
#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = nullptr);


signals:
    void clickedAt(QPoint pos);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
