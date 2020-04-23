#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form();
    form->show();
    color = 0;
    figure = 0;
    draw = false;
    emit sendData(color, figure, draw);
    connect(this, SIGNAL(sendData(short, short, bool)), form, SLOT(recieveData(short, short, bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_red_button_clicked()
{
    color = 0;
    emit sendData(color, figure, draw);
}

void MainWindow::on_green_button_clicked()
{
    color = 1;
    emit sendData(color, figure, draw);
}

void MainWindow::on_blue_button_clicked()
{
    color = 2;
    emit sendData(color, figure, draw);
}

void MainWindow::on_star_button_clicked()
{
    figure = 0;
    emit sendData(color, figure, draw);
}

void MainWindow::on_circle_button_clicked()
{
    figure = 1;
    emit sendData(color, figure, draw);
}

void MainWindow::on_square_button_clicked()
{
    figure = 2;
    emit sendData(color, figure, draw);
}

void MainWindow::on_rhombus_button_clicked()
{
    figure = 3;
    emit sendData(color, figure, draw);
}

void MainWindow::on_draw_button_clicked()
{
    draw = !draw;
    emit sendData(color, figure, draw);
}
