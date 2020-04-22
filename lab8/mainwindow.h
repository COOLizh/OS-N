#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qpainter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_paint_button_clicked();

    void on_clear_button_clicked();

    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    QPainter painter;
    bool isDraw;

};
#endif // MAINWINDOW_H
