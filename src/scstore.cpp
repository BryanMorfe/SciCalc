#include "include/scstore.h"

#include <QDebug>
#include <QDir>

/* Private Constants */
const QString DRIVER("QSQLITE");
const QString DBNAME(QDir::currentPath() + "SciCalc.db");

SCStore::SCStore(): saveThread(nullptr)
{

    if (QSqlDatabase::isDriverAvailable(DRIVER))
    {
        database = QSqlDatabase::addDatabase(DRIVER);
        database.setDatabaseName(DBNAME);

        if (!database.open())
            qWarning() << "Error:" << database.lastError();
        else
        {
            /* Create tables if they don't exist */
            QString queryStr = "CREATE TABLE IF NOT EXISTS expressions ";
            queryStr += "( expString VARCHAR(255) NOT NULL,";
            queryStr += "regDate TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP );";
            QSqlQuery query(queryStr);

            if (!query.isActive())
                qWarning() << "Error:" << query.lastError().text();

            database.close();

        }

        database.removeDatabase(DBNAME);

    }
}

SCStore::~SCStore()
{
    if (saveThread != nullptr)
        delete saveThread;
}

void SCStore::saveInExpression(const SCInExpression &inExp)
{

    if (saveThread == nullptr)
    {
        saveThread = QThread::create([inExp, this]() -> void {

            database = QSqlDatabase::addDatabase(DRIVER);
            database.setDatabaseName(DBNAME);
            if (database.open())
            {
                QString expString;

                for (auto token : inExp.getTokens())
                    expString = token.getToken() + " ";

                expString += inExp.getPartialToken();

                QString queryStr = "INSERT INTO expressions (expString) VALUES (\"";
                queryStr += expString + "\")";

                QSqlQuery query(queryStr);

                if (!query.isActive())
                    qWarning() << "Error:" << query.lastError().text();
                else {
                    qDebug() << "Expression saved.";
                }

                database.close();
            }
        });

        saveThread->start();

    }
    else
    {
        if (saveThread->isRunning())
            saveThread->terminate();
        delete saveThread;
        saveThread = nullptr;
        saveInExpression(inExp);
    }

}
