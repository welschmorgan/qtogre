#ifndef NEWITEMWIZARD_H
#define NEWITEMWIZARD_H

#include <QWizard>
#include <memory>

namespace Ui {
class NewItemWizard;
}

class IProjectItemConfig;

/**
 * @brief The NewItemWizard class
 */
class NewItemWizard : public QWizard
{
    Q_OBJECT
public:
    typedef IProjectItemConfig              Template;
    typedef std::list<Template*>            TemplateList;

    explicit NewItemWizard(const QString &base_name = QString(), const QString &project_dir = QString(), QWidget *parent = nullptr);
    ~NewItemWizard();

    /**
     * @brief getTemplates
     * @return the available item templates
     */
    TemplateList            *getTemplates();
    const TemplateList      *getTemplates() const;


    void                clearItemTypes();
protected:
    void                registerItemTypes();

protected slots:
    void                onBrowseDirectory();
    void                onItemTemplateChanged(const QString &);
private:
    Ui::NewItemWizard                   *ui;
    std::unique_ptr<TemplateList>       mTemplates;
};

#endif // NEWITEMWIZARD_H
