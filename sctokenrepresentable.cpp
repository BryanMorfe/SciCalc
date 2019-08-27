#include "sctokenrepresentable.h"

SCTokenRepresentable::SCTokenRepresentable() {}

SCTokenRepresentable::SCTokenRepresentable(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep):
    SCToken(tk, tt),
    tokenRepresentation(rep)
{}

SCTokenRepresentable::SCTokenRepresentable(const SCTokenRepresentable &other):
    SCToken(other.token, other.type),
    tokenRepresentation(other.tokenRepresentation)
{}

void SCTokenRepresentable::setRepresentation(const QString &rep)
{
    tokenRepresentation = rep;
}

QString SCTokenRepresentable::getRepresentation() const
{
    return tokenRepresentation;
}
