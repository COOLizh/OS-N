#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QMessageBox>

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
    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_clear_button_clicked();

    void on_to_right_button_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *left_model, *right_model;
    QStringList left_list, right_list;
    bool isOkInput(QString &str);
};
#endif // MAINWINDOW_H
