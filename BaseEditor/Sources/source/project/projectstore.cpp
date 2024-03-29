#include "include/project/projectstore.h"
#include "include/project/projectwidget.h"
#include "include/project/projectitem.h"
#include "include/project/projectitemconfig.h"

ProjectStore::ProjectStore(ProjectWidget *parent)
    : QObject(parent)
    , mTree(parent)
    , rootItem(nullptr)
    , _modified(false)
{
}

ProjectStore::~ProjectStore()
{
    clear();
}

ProjectItem     *ProjectStore::createRoot(const QString &name)
{
    if (rootItem)
        return (rootItem);
    rootItem = new ProjectItem(new ProjectItemConfig::Root(name) , name, nullptr, mTree);
    mTree->addTopLevelItem(rootItem);
    return (rootItem);
}

ProjectItem     *ProjectStore::getRoot(){ return (rootItem); }
const ProjectItem     *ProjectStore::getRoot() const { return (rootItem); }

void             ProjectStore::destroyRoot()
{ if (rootItem) delete rootItem, rootItem = nullptr; }

ProjectItem     *ProjectStore::createItem(IProjectItemConfig *type, const QString &name)
{
    if (!rootItem)
        return (rootItem);
    ProjectItem *item = rootItem->createItem(type, name);
    _setModified(true);
    return (item);
}
ProjectItem     *ProjectStore::getRootItem()
{
    return (rootItem);
}


void            ProjectStore::clear()
{
    destroyRoot();
}

bool            ProjectStore::isModified() const
{
    return (_modified);
}

void            ProjectStore::_setModified(bool state)
{
    _modified = state;
    if (rootItem)
        rootItem->setText(0, mTree->getName() + (state ? " *" : ""));
}
