#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>

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
    void change_picture();
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    short picture_num;
    float x_start, y_start, x_end, y_end;
    QTimer *change_picture_timer;
    QString picture_format, path_to_picture;
};
#endif // MAINWINDOW_H
