#include "customButton.h"

#include <QBitmap>

CustomButton::CustomButton():
    QPushButton()
{
    setMaximumWidth(30);
    setMaximumHeight(30);
    setMinimumWidth(30);
    setMinimumHeight(30);

    setStyleSheet( "QPushButton {background-color: transparent}" );
}

void CustomButton::setIcon(const QString &fileName, const QColor &color)
{
    QPixmap pixmap(fileName);
    QBitmap mask = pixmap.createMaskFromColor(QColor("black"),Qt::MaskOutColor);
    pixmap.fill((QColor("red")));
    pixmap.setMask(mask);

    QPushButton::setIcon(QIcon(pixmap));
}
