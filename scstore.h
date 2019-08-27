#ifndef SCSTORE_H
#define SCSTORE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QThread>

#include "scinexpression.h"

class SCStore
{
public:
    SCStore();
    ~SCStore();

    void saveInExpression(const SCInExpression &inExp);
private:
    QSqlDatabase database;
    QThread *saveThread;
};

#endif // SCSTORE_H
