#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "actionstade.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pushButton_2->hide();
    Load(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
        if (ui->radioButton->isChecked())
        {
            Load(obj1.d1_Key);
        }

        if (ui->radioButton_2->isChecked())
        {
            Load(obj1.d2_Key);
        }

        if (ui->radioButton_3->isChecked())
        {
            Load(obj1.d3_Key);
        }

}

void MainWindow::Load(int a)
{


    obj1.GetFromDB(a);
    ui->label->setText(obj1.Text);
    if (!obj1.Died)
    {
        if (obj1.d1_Text != "")
        {
            ui->radioButton->show();
            ui->radioButton->setText(obj1.d1_Text);
        }
        else
        {
            ui->radioButton->hide();
        }
        if (obj1.d2_Text != "")
        {
            ui->radioButton_2->show();
            ui->radioButton_2->setText(obj1.d2_Text);
        }
        else
        {
            ui->radioButton_2->hide();
        }
        if (obj1.d3_Text != "")
        {
            ui->radioButton_3->show();
            ui->radioButton_3->setText(obj1.d3_Text);
        }
        else
        {
            ui->radioButton_3->hide();
        }
    }
    else
    {
        ui->label->setText(obj1.Text);
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->radioButton_3->hide();
        ui->pushButton->setVisible(0);
        ui->pushButton_2->show();
    }





}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
