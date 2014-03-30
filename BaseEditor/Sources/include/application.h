#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

namespace Ui
{
    class mainwindow;
}

class ProjectWidget;

class Application : public QMainWindow
{
    Q_OBJECT
public:
    explicit Application(QWidget *parent = 0);
    ~Application();

protected:
    Ui::mainwindow *ui;
    friend class ProjectWidget;
signals:

public slots:
    void    onCreateProject();
    void    onOpenProject();
    void    onSaveProject();
    void    onSaveAsProject();
    void    onCloseProject();

    void    onAddItem();
    void    onRemoveItem();
    void    onEditItem();

    void    closeEvent(QCloseEvent *);
};

#endif // APPLICATION_H
