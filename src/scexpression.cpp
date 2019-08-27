#include "include/scexpression.h"

SCExpression::SCExpression() {}

SCExpression::SCExpression(const QList<SCToken> &tks): tokens(tks) {}

SCExpression::~SCExpression() {}

QList<SCToken> SCExpression::getTokens() const
{
    return tokens;
}

void SCExpression::addToken(const SCToken &tk)
{
    tokens.append(tk);
}

