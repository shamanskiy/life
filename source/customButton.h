#pragma once

#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:

    CustomButton();

    void setIcon(const QString &fileName, const QColor &color);

public slots:

protected slots:

signals:

protected:

};
