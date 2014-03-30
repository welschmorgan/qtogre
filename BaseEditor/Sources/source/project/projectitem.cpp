#include "include/project/projectitem.h"
#include "include/project/projectstore.h"
#include "include/project/projectwidget.h"

ProjectItem::ProjectItem(IProjectItemConfig *config,
                         const QString &name,
                         ProjectItem *parent,
                         ProjectWidget * tree)
    : QTreeWidgetItem(tree, QStringList())
    , mTree(tree)
    , mConfig(config)
{
    config->setTag(name);
    setText(0, name);
    setText(1, config->str());
    parentItem = parent;
}

ProjectItem::~ProjectItem()
{
}

ProjectItem                 *ProjectItem::createItem(IProjectItemConfig *config, const QString &name)
{
    auto item = new ProjectItem(config, name, this, mTree);
    this->addChild(item);
    return (item);
}

