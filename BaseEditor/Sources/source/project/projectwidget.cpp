#include "include/projectwidget.h"
#include "include/application.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <qabstractbutton.h>
#include <qfiledialog.h>
#include <qinputdialog.h>

/**
 * @brief ProjectWidget::ProjectWidget
 * @param parent
 */
ProjectWidget::ProjectWidget(QWidget *parent)
    : QTreeWidget(parent)
    , mApp(nullptr)
    , mStore(nullptr)
    , mCreated(false)
{
}

/**
 * @brief ProjectWidget::~ProjectWidget
 */
ProjectWidget::~ProjectWidget()
{
}

/**
 * @brief createProject
 * @param name The name for the project
 * @return true if successful
 */
bool        ProjectWidget::createProject(const std::string &name)
{
    mName = name;
    if (mName.empty())
        mName = QInputDialog::getText(this, tr("Create project"), tr("Project name:")).toStdString();
    if (mName.empty())
        return (false);
    mPath.clear();
    mStore->_setModified(true);
    mStore->createRoot(mName);
    mCreated = true;
    enableToolbox();
    return (true);
}

/**
 * @brief ProjectWidget::openProject
 * @return true if successful
 */
bool        ProjectWidget::openProject()
{
    QString path = QFileDialog::getOpenFileName(this, "Open Project", PROJECT_BASE_PATH, PROJECT_FILTERS);
    if (!path.isEmpty())
    {
        if (_load(path.toStdString()))
        {
            mStore->_setModified(false);
            enableToolbox();
            return (true);
        }
    }
    return (false);
}

/**
 * @brief ProjectWidget::saveProjectAs
 * @return true if save successful
 */
bool        ProjectWidget::saveProjectAs()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save Project As ..."), PROJECT_BASE_PATH, PROJECT_FILTERS);
    if (path.isEmpty())
        return (false);
    if (_save(path.toStdString()))
    {
        mPath = path.toStdString();
        return (true);
    }
    return (false);
}

/**
 * @brief ProjectWidget::saveProject
 * @return true if successful
 */
bool        ProjectWidget::saveProject()
{
    QString path;
    if (mPath.empty())
        path = QFileDialog::getSaveFileName(this, tr("Save Project"), PROJECT_BASE_PATH, PROJECT_FILTERS);
    if (path.isEmpty())
        return (false);
    if (_save(path.toStdString()))
    {
        mPath = path.toStdString();
        mStore->_setModified(false);
        enableToolbox();
        return (true);
    }
    return (false);
}

/**
 * @brief ProjectWidget::closeProject
 * @return true if successful
 */
bool        ProjectWidget::closeProject()
{
    if (mStore->isModified())
    {
        int     code;
        QMessageBox mbox(QMessageBox::Question,
                         tr("Close modified project ?"),
                         tr("The current project has been modified, do you really want to quit ?"),
                         QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
        mbox.button(QMessageBox::Yes)->setText(tr("&Save && Quit"));
        mbox.button(QMessageBox::No)->setText(tr("&Lose Changes"));
        if ((code = mbox.exec()) == QMessageBox::Yes)
        {
            if (!saveProject())
                return (false);
        }
        else if (code == QMessageBox::Cancel)
            return (false);
    }
    mStore->clear();
    mStore->_setModified(false);
    mCreated = false;
    enableToolbox();
    return (true);
}

/**
 * @brief ProjectWidget::getName
 * @return
 */
const std::string       &ProjectWidget::getName(){ return (mName); }
/**
 * @brief ProjectWidget::getPath
 * @return
 */
const std::string       &ProjectWidget::getPath(){ return (mName); }

/**
 * @brief ProjectWidget::getStore
 * @return
 */
ProjectStore            *ProjectWidget::getStore(){ return (mStore); }
const ProjectStore      *ProjectWidget::getStore() const{ return (mStore); }

/**
 * @brief ProjectWidget::isModified
 * @return true if the project is different from saved version
 */
bool                    ProjectWidget::isModified() const{ return (mStore ? mStore->isModified() : false); }

/**
 * @brief ProjectWidget::isCreated
 * @return true if the project is created
 */
bool                    ProjectWidget::isCreated() const{ return (mCreated); }

/**
 * @brief ProjectWidget::_save
 * @param path The path to the project file
 * @return true if success
 */
bool        ProjectWidget::_save(const std::string &path)
{
    if (closeProject())
    {
        mPath = path;
        mStore->_setModified(false);
        return (true);
    }
    return (false);
}

/**
 * @brief ProjectWidget::_load
 * @param path The path to the project file
 * @return true if success
 */
bool        ProjectWidget::_load(const std::string &path)
{
    if (closeProject())
    {
        mPath = path;
        mStore->_setModified(false);
        return (true);
    }
    return (false);
}

void        ProjectWidget::enableToolbox()
{
    mApp->ui->btnAddProjectItem->setEnabled(mCreated);
    mApp->ui->btnRemoveProjectItem->setEnabled(mCreated);
    mApp->ui->btnEditProjectItem->setEnabled(mCreated);
    mApp->ui->actionSave->setEnabled(mCreated);
    mApp->ui->actionSave_As->setEnabled(mCreated);
    mApp->ui->actionClose->setEnabled(mCreated);
    mApp->ui->menuAdd->setEnabled(mCreated);
}

void        ProjectWidget::onNewItem()
{
}

void        ProjectWidget::onAddItem()
{
}

/**
 * @brief ProjectWidget::create
 * @param app The application class instance
 */
void        ProjectWidget::createWidget(Application * app)
{
    mApp = app;
    mStore = new ProjectStore(this);
    QMenu *menu = new QMenu(mApp->ui->btnAddProjectItem);
    menu->addAction(QIcon(":/icons/new.svg"), tr("New item"), this, SLOT(onNewItem));
    menu->addAction(QIcon(":/icons/open.svg"), tr("New item"), this, SLOT(onAddItem));
    mApp->ui->btnAddProjectItem->setMenu(menu);
    enableToolbox();
}

/**
 * @brief ProjectWidget::destroy
 */
void        ProjectWidget::destroyWidget()
{
    if (mStore)
        delete mStore, mStore = nullptr;
    if (mApp)
        mApp = nullptr;
}
