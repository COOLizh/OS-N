#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::recieveData(short color, short figure, bool draw)
{
    _color = color;
    _figure = figure;
    _draw = draw;
}

void Form::mousePressEvent(QMouseEvent *event)
{
    if(!_draw)
        return;
    x = event->x();
    y = event->y();
    repaint(x - 25, y - 25, 51, 51);
}

void Form::paintEvent(QPaintEvent *)
{
    painter.begin(this);
    switch(_color){
    case 0:
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.setPen(QPen(Qt::red));
        break;
    case 1:
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        painter.setPen(QPen(Qt::green));
        break;
    case 2:
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.setPen(QPen(Qt::blue));
        break;
    }
    switch(_figure){
    case 0:
        painter.drawText(QPoint(x, y), "STR");
        break;
    case 1:
        painter.drawEllipse(x - 25, y - 25, 50, 50);
        break;
    case 2:
        painter.drawRect(x - 25, y - 25, 50, 50);
        break;
    case 3:
        painter.drawLine(x - 25, y, x, y + 25);
        painter.drawLine(x, y + 25, x + 25, y);
        painter.drawLine(x + 25, y, x, y - 25);
        painter.drawLine(x, y - 25, x - 25, y);
        break;
    }
    painter.end();
}
