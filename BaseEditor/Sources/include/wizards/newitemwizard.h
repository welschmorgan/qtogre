#ifndef NEWITEMWIZARD_H
#define NEWITEMWIZARD_H

#include <QWizard>

namespace Ui {
class NewItemWizard;
}

class NewItemWizard : public QWizard
{
    Q_OBJECT

public:
    explicit NewItemWizard(QWidget *parent = 0);
    ~NewItemWizard();

private:
    Ui::NewItemWizard *ui;
};

#endif // NEWITEMWIZARD_H
