#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sw = new StopWatch(ui->label);
    l = new QListWidget();
    ui->verticalLayout->addWidget(l);
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sw;
    delete l;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text() == "Старт") {
        sw->start();
        ui->pushButton->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
    } else {
        sw->stop();
        ui->pushButton->setText("Старт");
        ui->pushButton_3->setEnabled(false);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    auto circleTime = sw->circle();
    l->insertItem(0, QString("Круг %1, время: %2")
                     .arg(l->count() + 1)
                     .arg(circleTime)   );
}


void MainWindow::on_pushButton_2_clicked()
{
    l->clear();
    sw->clear();
    ui->label->setText("00:00:00.000");
}

