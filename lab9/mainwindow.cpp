#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    picture_num = 0;
    x_start = 0;
    y_start = 0;
    x_end = 0;
    y_end = 0;
    picture_format = ".jpg";
    path_to_picture = "/home/vladislav/Рабочий стол/osis/OS-N/lab9/";
    change_picture_timer = new QTimer();
    connect(change_picture_timer, SIGNAL(timeout()), this, SLOT(change_picture()));
    change_picture_timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_picture()
{
    if(picture_num == 4)
    {
        picture_num = 0;
    }
    QPixmap pixmap(path_to_picture + QString::number(picture_num) + picture_format);
    picture_num++;
    ui->label->setPixmap(pixmap);


    if(x_start < x_end)
    {
        y_start = (((y_end - y_start) * 5) / (x_end - x_start)) + y_start;
        ui->label->setGeometry(ui->label->x()+5, y_start, ui->label->width(), ui->label->height());
        x_start += 5;
    } else if(x_start > x_end){
        y_start = (((y_end - y_start) * -5) / (x_end - x_start)) + y_start;
        ui->label->setGeometry(ui->label->x()-5, y_start, ui->label->width(), ui->label->height());
        x_start -= 5;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    x_end = event->x();
    y_end = event->y();
}

