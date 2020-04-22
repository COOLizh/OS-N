#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("/home/vladislav/Рабочий стол/osis/OS-N/lab8/clear.jpg");
    QIcon ButtonIcon(pixmap);
    ui->clear_button->setIconSize(pixmap.rect().size());
    ui->clear_button->setIcon(ButtonIcon);
    QPixmap pixmap2("/home/vladislav/Рабочий стол/osis/OS-N/lab8/paint.jpg");
    QIcon ButtonIcon2(pixmap2);
    ui->paint_button->setIconSize(pixmap2.rect().size());
    ui->paint_button->setIcon(ButtonIcon2);
    isDraw = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(isDraw){
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(10, 10, 10, 10);
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        painter.drawEllipse(100, 50, 150, 150);
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.drawEllipse(50, 50, 10, 100);
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        painter.drawEllipse(90, 100, 90, 100);
        painter.drawLine(0, 0, 25, 25);
        painter.drawRect(1, 1, 100, 100);
        isDraw = false;
    } else {
        painter.eraseRect(QRect(0, 0, 1000, 1000));
    }
}


void MainWindow::on_paint_button_clicked()
{
    isDraw = true;
    repaint();
}

void MainWindow::on_clear_button_clicked()
{
    repaint();
}
