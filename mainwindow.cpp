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
    ui->rb_setup1->setChecked(true);
    ui->psh_toogle->setText("Touch");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_bar_valueChanged(int value)
{
    if(ui->pb_bar->value() == 10){
        ui->pb_bar->setValue(0);
    }else if((value + ui->pb_bar->value()) > 10){
        ui->pb_bar->setValue(10);
    }else{
        ui->pb_bar->setValue((value + ui->pb_bar->value()));
    }
}

void MainWindow::on_psh_setup_clicked()
{
    if(ui->rb_setup1->isChecked() == true){
        on_pb_bar_valueChanged(1);
    }else{
        on_pb_bar_valueChanged(2);
    }
}


void MainWindow::on_psh_toogle_clicked()
{
    on_psh_toogle_toggled(true);
}


void MainWindow::on_psh_toogle_toggled(bool checked)
{
    on_pb_bar_valueChanged(5);
}

