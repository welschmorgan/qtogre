#include "application.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

/**
 * @brief Application::Application
 * @param parent The optionnal widget parent
 */
Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    ui->projectWidget->createWidget(this);
    connect(ui->actionQuit, &QAction::triggered, this, &Application::close);
    connect(ui->actionNew, &QAction::triggered, this, &Application::onCreateProject);
    connect(ui->actionOpen, &QAction::triggered, this, &Application::onOpenProject);
    connect(ui->actionSave, &QAction::triggered, this, &Application::onSaveProject);
    connect(ui->actionSave_As, &QAction::triggered, this, &Application::onSaveAsProject);
    connect(ui->actionClose, &QAction::triggered, this, &Application::onCloseProject);

    connect(ui->btnAddProjectItem, &QToolButton::triggered, this, &Application::onAddItem);
    connect(ui->btnEditProjectItem, &QToolButton::triggered, this, &Application::onEditItem);
    connect(ui->btnRemoveProjectItem, &QToolButton::triggered, this, &Application::onRemoveItem);
}

/**
 * @brief Application::~Application
 */
Application::~Application()
{
    ui->projectWidget->destroyWidget();
    delete ui;
}
void    Application::onAddItem()
{
}

void    Application::onRemoveItem()
{
}

void    Application::onEditItem()
{
}

void    Application::onCreateProject()
{ ui->projectWidget->createProject(); }

void    Application::onOpenProject()
{ ui->projectWidget->openProject(); }
void    Application::onSaveProject()
{ ui->projectWidget->saveProject(); }
void    Application::onSaveAsProject()
{ ui->projectWidget->saveProjectAs(); }
void    Application::onCloseProject()
{ ui->projectWidget->closeProject(); }

/**
 * @brief Application::closeEvent
 * @param e The event variable
 */
void    Application::closeEvent(QCloseEvent *e)
{
    if (ui->projectWidget->closeProject())
        e->accept();
    else
        e->ignore();
}
