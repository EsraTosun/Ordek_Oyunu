#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    showMaximized();
    ordeknesne = new ordek(this);
    anaLabel = ui->label;
    vurulmaLabel = ui->label_3;
    kacanLabel = ui->label_5;
    ordeknesne->ordekOlustur(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: resizeEvent(QResizeEvent *event)  {
    QMainWindow::resizeEvent(event);

    ui->label_2->setStyleSheet("color : green");
    ui->label_3->setStyleSheet("color : green");
    ui->label_4->setStyleSheet("color : red");
    ui->label_5->setStyleSheet("color : red");

    // QLabel'ın boyutunu güncelle
    //ui->label->setScaledContents(true); // Resmi QLabel boyutuna sığdır
    ui->label->setFixedSize(this->width() - 2*(ui->frame->width()), this->height());
    ui->frame->setFixedSize(ui->frame->width(), this->height());

    ui->label->move(5,ui->label->y()+10);
    ui->frame->move(ui->label->geometry().x() + ui->label->width(), ui->label->geometry().y());
}

