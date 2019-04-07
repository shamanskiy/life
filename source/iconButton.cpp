#include "iconButton.h"

#include <QBitmap>
#include <QMouseEvent>

#include "colorScheme.h"

IconButton::IconButton(const QString & _iconFileName, int iconSize):
    QPushButton(),
    iconFileName(_iconFileName),
    hoveredOver(false),
    pressed(false)
{
    setMaximumWidth(30);
    setMaximumHeight(30);
    setMinimumWidth(30);
    setMinimumHeight(30);

    setStyleSheet( "QPushButton {background-color: transparent}" );
    setIconSize(QSize(iconSize,iconSize));

    updateIcon();
    connect(this,SIGNAL(pressed()),this,SLOT(pressedSlot()));
    connect(this,SIGNAL(released()),this,SLOT(releasedSlot()));

}

void IconButton::setIcon(const QString &_iconFileName)
{
    iconFileName = _iconFileName;
    updateIcon();
}

void IconButton::enterEvent(QEvent *event)
{
    hoveredOver = true;
    event->accept();
    updateIcon();
}

void IconButton::leaveEvent(QEvent *event)
{
    hoveredOver = false;
    event->accept();
    updateIcon();
}

void IconButton::pressedSlot()
{
    pressed = true;
    updateIcon();
}

void IconButton::releasedSlot()
{
    pressed = false;
    updateIcon();
}

void IconButton::updateIcon()
{
    if (!iconFileName.isEmpty())
    {
        QPixmap pixmap(iconFileName);
        QBitmap mask = pixmap.createMaskFromColor(QColor("black"),Qt::MaskOutColor);
        if (pressed || !hoveredOver)
            pixmap.fill(QColor(LIFE_BASE_TEXT));
        else if (hoveredOver)
            pixmap.fill(QColor(LIFE_HOVER_TEXT));
        pixmap.setMask(mask);

        QPushButton::setIcon(QIcon(pixmap));
    }
}
