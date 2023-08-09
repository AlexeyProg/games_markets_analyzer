#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pr = new QProcess;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    con.runScript(pr,ui->lineEdit->text());
}


