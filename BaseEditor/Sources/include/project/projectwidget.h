#ifndef PROJECTWIDGET_H
# define PROJECTWIDGET_H

# include <QTreeWidget>
# include "projectstore.h"

# define PROJECT_BASE_PATH "./projects/"
# define PROJECT_FILTERS "All Project Files (*.proj);;All Files (*.*);;"

class Application;
class ProjectWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ProjectWidget(QWidget *parent = 0);
    ~ProjectWidget();

    bool        createProject(const std::string &name = std::string());
    bool        openProject();
    bool        saveProject();
    bool        saveProjectAs();
    bool        closeProject();

    const std::string       &getName();
    const std::string       &getPath();

    ProjectStore            *getStore();
    const ProjectStore      *getStore() const;

    bool                    isModified() const;
    bool                    isCreated() const;
    void                    enableToolbox();

protected:
    std::string     mName;
    std::string     mPath;
    Application     *mApp;
    ProjectStore    *mStore;
    bool            mCreated;

    bool        _save(const std::string &path);
    bool        _load(const std::string &path);
    void        createWidget(Application * app);
    void        destroyWidget();

    friend class Application;
signals:

public slots:
    void        onNewItem();
    void        onAddItem();
};

#endif // PROJECTWIDGET_H
