#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QCursor cursor = QCursor(QPixmap("/home/vladislav/Рабочий стол/osis/OS-N/lab6/cursor.png"), 0, 0);
    this->setCursor(cursor);
    QIcon icon = QIcon("/home/vladislav/Рабочий стол/osis/OS-N/lab6/icon.ico");
    this->setWindowIcon(icon);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move_label()));
    isLeft = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_label()
{
    if(!isLeft)
    {
        ui->label->setGeometry(ui->label->x() + 1, ui->label->y(), 67, 17);
    }
    else
    {
        ui->label->setGeometry(ui->label->x() - 1, ui->label->y(), 67, 17);
    }
    if(ui->label->x() == 340 || ui->label->x() == 0)
    {
        isLeft = !isLeft;
    }
}

void MainWindow::on_start_button_clicked()
{
    ui->label->setText("Text");
    timer->start(20);
}

void MainWindow::on_stop_button_clicked()
{
    timer->stop();
}
