#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class ClickableLabel : public QLabel {
    Q_OBJECT  // Required for using signals and slots

public:
    explicit ClickableLabel(QWidget* parent = nullptr);
    ~ClickableLabel();

signals:
    void clicked();  // Signal that will be emitted when the label is clicked

protected:
    void mousePressEvent(QMouseEvent* event) override;  // Override mouse click event
};

#endif // CLICKABLELABEL_H
