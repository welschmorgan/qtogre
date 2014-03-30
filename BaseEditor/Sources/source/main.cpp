#include "application.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application w;
    a.setOrganizationName("DarkSofts");
    a.setApplicationName("QOgre Editor");
    try
    {
        w.show();

        return (a.exec());
    }
    catch (std::exception & e)
    {
        QMessageBox mbox(QMessageBox::Information, QObject::tr("Fatal error occurred !"), e.what(), QMessageBox::Ok);
        mbox.exec();
    }
    catch (...)
    {
        QMessageBox mbox(QMessageBox::Information, QObject::tr("Fatal error occurred !"), QObject::tr("An unknown error occurred, please restart the application"), QMessageBox::Ok);
        mbox.exec();
    }
    return (EXIT_FAILURE);
}
