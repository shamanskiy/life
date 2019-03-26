#include "iconButton.h"

#include <QBitmap>
#include <QMouseEvent>

#include "colorScheme.h"

IconButton::IconButton(const QString & _iconFileName, int iconSize):
    QPushButton(),
    iconFileName(_iconFileName),
    hoveredOver(false)
{
    setMaximumWidth(30);
    setMaximumHeight(30);
    setMinimumWidth(30);
    setMinimumHeight(30);

    setStyleSheet( "QPushButton {background-color: transparent}" );
    setIconSize(QSize(iconSize,iconSize));

    updateIcon();
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

void IconButton::updateIcon()
{
    if (!iconFileName.isEmpty())
    {
        QPixmap pixmap(iconFileName);
        QBitmap mask = pixmap.createMaskFromColor(QColor("black"),Qt::MaskOutColor);
        if (hoveredOver)
            pixmap.fill(QColor(LIFE_HOVER_TEXT));
        else
            pixmap.fill(QColor(LIFE_BASE_TEXT));
        pixmap.setMask(mask);

        QPushButton::setIcon(QIcon(pixmap));
    }
}
