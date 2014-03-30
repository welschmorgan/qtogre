#include "application.h"
#include "ui_mainwindow.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Application::~Application()
{
    delete ui;
}
