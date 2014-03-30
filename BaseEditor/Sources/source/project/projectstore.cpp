#include "include/projectstore.h"
#include "include/projectwidget.h"
#include "include/projectitem.h"
#include "include/projectitemconfig.h"

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

ProjectItem     *ProjectStore::createRoot(const std::string &name)
{
    if (rootItem)
        return (rootItem);
    rootItem = new ProjectItem(new ProjectItemConfig::Root , name, nullptr, mTree);
    mTree->addTopLevelItem(rootItem);
    return (rootItem);
}

ProjectItem     *ProjectStore::getRoot(){ return (rootItem); }
const ProjectItem     *ProjectStore::getRoot() const { return (rootItem); }

void             ProjectStore::destroyRoot()
{ if (rootItem) delete rootItem, rootItem = nullptr; }

ProjectItem     *ProjectStore::createItem(IProjectItemConfig *type, const std::string &name)
{
    if (!rootItem)
        return (rootItem);
    ProjectItem *item = rootItem->createItem(type, name);
    _modified = true;
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
}
