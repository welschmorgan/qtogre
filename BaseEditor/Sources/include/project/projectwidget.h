#ifndef PROJECTWIDGET_H
# define PROJECTWIDGET_H

# include <QTreeWidget>
# include "include/project/projectstore.h"
# include "include/enablers.hpp"

# define PROJECT_BASE_PATH "./projects/"
# define PROJECT_FILTERS "All Project Files (*.proj);;All Files (*.*);;"

class Application;
class ProjectWidget
        : public QTreeWidget
        , public enable::tag<ProjectWidget, QString>
{
    Q_OBJECT
public:
    explicit ProjectWidget(QWidget *parent = 0);
    ~ProjectWidget();

    bool        createProject(const QString &name = QString());
    bool        openProject();
    bool        saveProject();
    bool        saveProjectAs();
    bool        closeProject();

    const QString           &getName() const;
    void                    setName(const QString &name);

    void                    setPath(const QString &path);
    const QString           &getPath() const;

    ProjectStore            *getStore();
    const ProjectStore      *getStore() const;

    bool                    isModified() const;
    bool                    isCreated() const;
    void                    enableToolbox();

protected:
    QString         mName;
    QString         mPath;
    Application     *mApp;
    ProjectStore    *mStore;
    bool            mCreated;

    bool        _save(const QString &path);
    bool        _load(const QString &path);
    void        createWidget(Application * app);
    void        destroyWidget();

    friend class Application;
signals:

public slots:
    void        onNewItem();
    void        onAddItem();
};

#endif // PROJECTWIDGET_H
