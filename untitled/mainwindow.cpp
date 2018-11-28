#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    char str[] = "root:x::0:root:/root:/bin/bash:";
    char *buf;
    char *token;
    buf = str;
    while((token = strtok(buf, ":")) != NULL){
    printf("%s\n", token);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
