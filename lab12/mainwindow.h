#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"
#include <QMutex>
#include <QSemaphore>

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
    void sema(QString txt);
    void mtx(QString txt);

private:
    Ui::MainWindow *ui;
    QMutex mutex;
    QSemaphore semaphore;
};
#endif // MAINWINDOW_H
