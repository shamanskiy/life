#pragma once

#include <QLabel>

class PatternSelector : public QLabel
{
    Q_OBJECT
public:

    PatternSelector();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    void drawMesh(QPainter& painter);

protected:

};
