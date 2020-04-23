#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void mousePressEvent(QMouseEvent *event);
    void recieveData(short color, short figure, bool draw);
    void paintEvent(QPaintEvent *);

private:
    Ui::Form *ui;
    short _color, _figure;
    bool _draw;
    int x, y;
    QPainter painter;
};

#endif // FORM_H
