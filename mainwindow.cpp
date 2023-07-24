#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_bar->setMaximum(10);
    ui->pb_bar->setMinimum(0);
    ui->pb_bar->setValue(0);
    ui->cb_nameGames->addItem("Bioshok");
    ui->cb_nameGames->addItem("Stalker");
    ui->cb_nameGames->addItem("Starfield");
    ui->cb_nameGames->addItem("Metro 2033");
    ui->rb_setup1->setText("10%");
    ui->rb_setup2->setText("20%");
    ui->psh_setup->setText("Setup");
    count = 0;
    flag_click = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_bar_valueChanged(int value)
{
    if(ui->pb_bar->value() == 10){
        ui->pb_bar->setValue(0);
    }else if(value > 10){
        ui->pb_bar->setValue(ui->pb_bar->value() + (10 - ui->pb_bar->value()));
    }else{
        ui->pb_bar->setValue((value));
    }
}


void MainWindow::on_psh_setup_toggled(bool checked)
{
    if(checked){
        if(ui->rb_setup1->isChecked() == false && ui->rb_setup2->isChecked() == false){
            return;
        }else if(ui->rb_setup1->isChecked() == true){
            on_pb_bar_valueChanged(count += 1);
        }else{
            on_pb_bar_valueChanged(count += 2);
        }
    }else{
        on_pb_bar_valueChanged(count += 3);
    }
}


void MainWindow::on_psh_setup_clicked()
{
    if(flag_click)
        flag_click = false;
    else
        flag_click = true;
    on_psh_setup_toggled(flag_click);
}

