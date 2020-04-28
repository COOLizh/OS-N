#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Thread *firstThread = new Thread(ui->label->x(), 1);
    Thread *secondThread = new Thread(ui->label->x(), 5);
    Thread *thirdThread = new Thread(ui->label->x(), 10);
    connect(firstThread, SIGNAL(sendData(int)), this, SLOT(move_label_1(int)));
    connect(secondThread, SIGNAL(sendData(int)), this, SLOT(move_label_2(int)));
    connect(thirdThread, SIGNAL(sendData(int)), this, SLOT(move_label_3(int)));
    firstThread->start();
    secondThread->start();
    thirdThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_label_1(int x)
{
    ui->label->setGeometry(x, ui->label->y(), ui->label->width(), ui->label->height());
}

void MainWindow::move_label_2(int x)
{
    ui->label_2->setGeometry(x, ui->label_2->y(), ui->label_2->width(), ui->label_2->height());
}

void MainWindow::move_label_3(int x)
{
    ui->label_3->setGeometry(x, ui->label_3->y(), ui->label_3->width(), ui->label_3->height());
}

