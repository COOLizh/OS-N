#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    left_model = new QStringListModel(this);
    right_model = new QStringListModel(this);
    ui->listView->setModel(left_model);
    ui->listView_2->setModel(right_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isOkInput(QString &str)
{
    QString result;
    int left_idx = 0, right_idx = str.length() - 1;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            left_idx = i;
            break;
        }
        if(i == str.length() - 1 && str[i] == ' ')
        {
            return false;
        }
    }
    for(int i = str.length() - 1; i >= 0; i--)
    {
        if(str[i] != ' ')
        {
            right_idx = i;
            break;
        }
    }
    for(int i = left_idx; i <= right_idx; i++)
    {
        result.append(str[i]);
    }
    for(int i = 0; i < left_list.size(); i++)
    {
        if(result == left_list[i])
        {
            return false;
        }
    }
    str = result;
    return true;
}


void MainWindow::on_add_button_clicked()
{
    QString tmp = ui->lineEdit->text();
    if(isOkInput(tmp)){
        left_list = left_model->stringList();
        left_list.append(tmp);
        left_model->setStringList(left_list);
    }
    else
    {
        QMessageBox::warning(this, "Is not correct input","String can not be empty, consists with only spaces and also repeat with the entered lines!");
    }
    ui->lineEdit->clear();
}

void MainWindow::on_delete_button_clicked()
{
    if((left_list.size() == 0 && right_list.size() == 0) || (ui->listView->currentIndex().row() == - 1 && ui->listView_2->currentIndex().row() == -1))
    {
        QMessageBox::warning(this, "Nothing to delete","You must select items to delete!");
    }
    else
    {
        if(left_list.size() != 0)
        {
            left_list.removeAt(ui->listView->currentIndex().row());
            left_model->setStringList(left_list);
        }
        if(right_list.size() != 0)
        {
            right_list.removeAt(ui->listView_2->currentIndex().row());
            right_model -> setStringList(right_list);
        }
    }
}

void MainWindow::on_clear_button_clicked()
{
    if(left_list.size() == 0 && right_list.size() == 0)
    {
        QMessageBox::warning(this, "Nothing to clear","Nothing to clear!");
    }
    else
    {
        left_list.clear();
        right_list.clear();
        left_model -> setStringList(left_list);
        right_model -> setStringList(right_list);
    }
}

void MainWindow::on_to_right_button_clicked()
{
    int idx = ui->listView->currentIndex().row();
    if(idx != -1)
    {
        QString tmp = left_list[idx];
        bool isOk = true;
        for(auto &item : right_list)
        {
            if(tmp == item)
            {
                isOk = false;
                break;
            }
        }
        if(isOk)
        {
            left_list.removeAt(idx);
            right_list.append(tmp);
            left_model -> setStringList(left_list);
            right_model -> setStringList(right_list);
        }
        else
        {
            QMessageBox::warning(this, "Repeating element","This element also exists in right listview!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Nothing to move","Nothing to move!");
    }
}

