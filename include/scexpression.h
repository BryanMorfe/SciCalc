#ifndef SCEXPRESSION_H
#define SCEXPRESSION_H

#include "sctoken.h"
#include <QList>

class SCExpression
{
public:
    SCExpression();
    SCExpression(const QList<SCToken> &tks);

    virtual ~SCExpression();

    QList<SCToken> getTokens() const;
    virtual bool addStringToken(const QString &str) = 0;

    void addToken(const SCToken &tk);

protected:
    QList<SCToken> tokens;

};

#endif // SCEXPRESSION_H
