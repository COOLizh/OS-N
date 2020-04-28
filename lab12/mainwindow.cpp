#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Thread *firstThread = new Thread("String1");
    Thread *secondThread = new Thread("String2");
    Thread *thirdThread = new Thread("String3");
    Thread *fourthThread = new Thread("String1");
    Thread *fifthThread = new Thread("String2");
    Thread *sixThread = new Thread("String3");
    connect(firstThread, SIGNAL(sendData(QString)), this, SLOT(mtx(QString)));
    connect(secondThread, SIGNAL(sendData(QString)), this, SLOT(mtx(QString)));
    connect(thirdThread, SIGNAL(sendData(QString)), this, SLOT(mtx(QString)));
    connect(fourthThread, SIGNAL(sendData(QString)), this, SLOT(sema(QString)));
    connect(fifthThread, SIGNAL(sendData(QString)), this, SLOT(sema(QString)));
    connect(sixThread, SIGNAL(sendData(QString)), this, SLOT(sema(QString)));
    semaphore.release(1);
    firstThread->start();
    secondThread->start();
    thirdThread->start();
    fourthThread->start();
    fifthThread->start();
    sixThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sema(QString txt)
{
    semaphore.acquire(1);
    ui->label_2->setText(txt);
    semaphore.release(1);
}

void MainWindow::mtx(QString txt)
{
    mutex.lock();
    ui->label->setText(txt);
    mutex.unlock();
}

