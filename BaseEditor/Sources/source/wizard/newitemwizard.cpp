#include "include/wizards/newitemwizard.h"
#include "include/project/projectitemconfig.h"
#include <list>
#include "ui_newitemwizard.h"
#include <QFileDialog>

/*
 * CTOR
 **/
NewItemWizard::NewItemWizard(const QString &base_name, const QString &project_dir, QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::NewItemWizard)
    , mTemplates(new ItemList)
{
    ui->setupUi(this);
    ui->nameLineEdit->setText(base_name);
    ui->nameLineEdit->setFocus();
    ui->directoryPushButton->setText(project_dir);
    connect(ui->directoryPushButton, SIGNAL(toggled(bool)), this, SLOT(onBrowseDirectory()));

    registerItemTypes();
    connect(ui->typeList, SIGNAL(currentTextChanged(QString)), this, SLOT(onItemTemplateChanged(const QString &)));
}

NewItemWizard::~NewItemWizard()
{
    clearItemTypes();
    delete ui;
}

TemplateList            *NewItemWizard::getTemplates(){ return (mTemplates.get()); }
const TemplateList      *NewItemWizard::getTemplates() const{ return (mTemplates.get()); }

void                NewItemWizard::clearItemTypes()
{
    for(auto i = mTemplates->begin();
        i != mTemplates->end();
        i++)
    {
        if (*i)
            delete (*i), (*i) = nullptr;
    }
    mTemplates->clear();
}

/***
 * Types
 **/
void                NewItemWizard::registerItemTypes()
{
    mTemplates->push_back(new ProjectItemConfig::Billboard);
    mTemplates->push_back(new ProjectItemConfig::Light);
    mTemplates->push_back(new ProjectItemConfig::Material);
    mTemplates->push_back(new ProjectItemConfig::Mesh);
    mTemplates->push_back(new ProjectItemConfig::Node);
    mTemplates->push_back(new ProjectItemConfig::Particle);
    mTemplates->push_back(new ProjectItemConfig::Root);
    mTemplates->push_back(new ProjectItemConfig::StaticGeometry);
}


void                NewItemWizard::onBrowseDirectory()
{
    QString path = QFileDialog::getExistingDirectory(this, "Choose item path:", ui->directoryPushButton->text());
    if (!path.isEmpty())
        ui->directoryPushButton->setText(path);
}

/**
 * @brief NewItemWizard::onItemTemplateChanged
 * Called whenever
 */
void                NewItemWizard::onItemTemplateChanged(const QString &)
{
}
