#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(short color, short figure, bool draw);

private slots:
    void on_red_button_clicked();

    void on_green_button_clicked();

    void on_blue_button_clicked();

    void on_star_button_clicked();

    void on_circle_button_clicked();

    void on_square_button_clicked();

    void on_rhombus_button_clicked();

    void on_draw_button_clicked();

private:
    Form *form;
    Ui::MainWindow *ui;
    short color, figure;
    bool draw;
};
#endif // MAINWINDOW_H
