#include "include/wizards/newitemwizard.h"
#include "ui_newitemwizard.h"

NewItemWizard::NewItemWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::NewItemWizard)
{
    ui->setupUi(this);
}

NewItemWizard::~NewItemWizard()
{
    delete ui;
}
