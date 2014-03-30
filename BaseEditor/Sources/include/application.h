#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class Application : public QMainWindow
{
    Q_OBJECT
public:
    explicit Application(QWidget *parent = 0);
    ~Application();

private:
    Ui::MainWindow *ui;
signals:

public slots:

};

#endif // APPLICATION_H
