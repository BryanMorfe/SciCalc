#include "include/sctoken.h"

SCToken::SCToken() {}

SCToken::SCToken(const QString &tk, const SCTokenTypes::TokenType &tt): token(tk), type(tt) {}

SCToken::SCToken(const SCToken &other): token(other.token), type(other.type) {}

void SCToken::setToken(const QString &tk)
{
    token = tk;
}

void SCToken::setType(const SCTokenTypes::TokenType &tt)
{
    type = tt;
}

QString SCToken::getToken() const
{
    return token;
}

SCTokenTypes::TokenType SCToken::getType() const
{
    return type;
}

