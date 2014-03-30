#include "include/projectitem.h"
#include "include/projectstore.h"
#include "include/projectwidget.h"

ProjectItem::ProjectItem(IProjectItemConfig *config,
                         const std::string &name,
                         ProjectItem *parent,
                         ProjectWidget * tree)
    : QTreeWidgetItem(tree, QStringList())
    , mTree(tree)
    , mConfig(config)
{
    config->setTag(name);
    setText(0, QString::fromStdString(name));
    setText(1, QString::fromStdString(config->str()));
    parentItem = parent;
}

ProjectItem::~ProjectItem()
{
}

ProjectItem                 *ProjectItem::createItem(IProjectItemConfig *config, const std::string &name)
{
    auto item = new ProjectItem(config, name, this, mTree);
    this->addChild(item);
    return (item);
}

