#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QAbstractItemView>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class IProjectItemConfig;
class ProjectItem;
class ProjectWidget;

/**
 * @brief The ProjectStore class
 */
class ProjectStore : public QObject
{
    Q_OBJECT

public:
    ProjectStore(ProjectWidget *parent = 0);
    virtual ~ProjectStore();

    ProjectItem             *createItem(IProjectItemConfig *type,
                                        const QString &name);
    ProjectItem             *getRootItem();
    ProjectItem             *createRoot(const QString &name);

    ProjectItem             *getRoot();
    const ProjectItem       *getRoot() const ;

    void                    destroyRoot();

    bool        isModified() const;
    void        _setModified(bool state);

    void        clear();

private:
    ProjectWidget   *mTree;
    ProjectItem     *rootItem;
    bool            _modified;
};

#endif // PROJECTSTORE_H
