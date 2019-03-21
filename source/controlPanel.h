#pragma once

#include <QLabel>

class ControlPanel : public QLabel
{
    Q_OBJECT
public:

    ControlPanel();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

protected:

};
