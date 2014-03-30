#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <QTreeWidgetItem>
#include <QVariant>
# include "include/project/projectitemconfig.h"
# include <memory>

class ProjectWidget;

/**
 * @brief The ProjectItem class
 */
class ProjectItem : public QTreeWidgetItem
{
public:
    ProjectItem(IProjectItemConfig *config,
                const QString &name = QString(),
                ProjectItem *parent = nullptr,
                ProjectWidget *tree = nullptr);
    ~ProjectItem();

    bool                        isType(IProjectItemConfig::Type t) const{ return (mConfig->type() == t); }
    IProjectItemConfig::Type    getType() const {return (mConfig->type());}
    IProjectItemConfig          *getConfig(){return (mConfig.get()); }
    ProjectItem                 *createItem(IProjectItemConfig *config,
                                            const QString &name);

private:
    QVariant                mValue;
    ProjectItem             *parentItem;
    ProjectWidget           *mTree;
    std::unique_ptr<IProjectItemConfig>   mConfig;
};

#endif // PROJECTITEM_H
