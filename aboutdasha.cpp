#include "aboutdasha.h"
#include "ui_aboutdasha.h"
#include <QPaintEvent>
#include <QPainter>
AboutDasha::AboutDasha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDasha)
{
    ui->setupUi(this);
}

AboutDasha::~AboutDasha()
{
    delete ui;
}

void AboutDasha::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //кузов
    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(138,70,352,70);
    painter.drawLine(350,70,350, 200);
    painter.drawLine(352,200,138,200);
    painter.drawLine(140,200,140,70);

    //кабина
    painter.drawLine(140,130,90,130);
    painter.drawLine(90,128,80,150);
    painter.drawLine(82,150,50,150);
    painter.drawLine(50,148,50,200);
    painter.drawLine(48,200,140,200);

    //колеса
    QRectF rectangle(140.0, 200.0, 40.0, 40.0);
    painter.drawEllipse(rectangle);
    QRectF rectangle2(290.0, 200.0, 40.0, 40.0);
    painter.drawEllipse(rectangle2);

    //дверь
    QColor koral = QColor::fromRgb(255,153,153);
    QPainter painter2(this);
    painter2.setPen(QPen(koral, 5, Qt::SolidLine, Qt::FlatCap));
    painter2.drawLine(88,145,132,145);
    painter2.drawLine(130,145,130,190);
    painter2.drawLine(132,190,88,190);
    painter2.drawLine(90,190,90,145);
}






















