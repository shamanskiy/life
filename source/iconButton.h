#pragma once

#include <QPushButton>

class IconButton : public QPushButton
{
    Q_OBJECT
public:

    IconButton(const QString & _iconFileName, int iconSize = 20);

    void setIcon(const QString & _iconFileName);

public slots:


protected slots:
    virtual void pressedSlot();
    virtual void releasedSlot();

signals:

protected:

    virtual void enterEvent(QEvent * event);
    virtual void leaveEvent(QEvent * event);

    void updateIcon();

protected:
    QString iconFileName;
    bool hoveredOver;
    bool pressed;

};
