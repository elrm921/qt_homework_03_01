#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "QString"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rb1->setText("button1");
    ui->rb1->setChecked(true);
    ui->rb2->setText("button2");
    ui->rb2->setChecked(false);

    for (int i=0; i<10; i++) {
        ui->comboBox->addItem("Item" + QString::number(i));
    }

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);

    ui->pushButton->setText("start");
    ui->pushButton->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int pb_value = ui->progressBar->value();
    if (pb_value < 10) {
        ui->progressBar->setValue(pb_value+1);
    }
    else {
        ui->progressBar->setValue(0);
    }
}


void MainWindow::on_pushButton_toggled(bool checked)
{
    qDebug() << checked;
}

