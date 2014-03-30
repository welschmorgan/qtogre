#ifndef PROJECTSTORE_H
#define PROJECTSTORE_H

#include <QAbstractTableModel>

class ProjectStore : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ProjectStore(QObject *parent = 0);

signals:

public slots:

};

#endif // PROJECTSTORE_H
