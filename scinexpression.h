#ifndef SCINEXPRESSION_H
#define SCINEXPRESSION_H

#include "scexpression.h"
#include "sctoken.h"

class SCInExpression : public SCExpression
{
public:
    SCInExpression();

    QString getPartialToken() const;

    bool addPartialToken(const QChar &ch);
    bool addStringToken(const QString &str);
    void delLastToken();
    void clear();

private:

    bool isPartialTokenFullToken() const;

    QString partialToken;
    SCTokenTypes::TokenType lastTokenType;
};

#endif // SCINEXPRESSION_H
