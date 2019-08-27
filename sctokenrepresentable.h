#ifndef SCTOKENREPRESENTABLE_H
#define SCTOKENREPRESENTABLE_H

#include "sctoken.h"

class SCTokenRepresentable : public SCToken
{
public:
    SCTokenRepresentable();
    SCTokenRepresentable(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep);
    SCTokenRepresentable(const SCTokenRepresentable &other);

    void setRepresentation(const QString &rep);

    QString getRepresentation() const;

protected:
    QString tokenRepresentation;
};

#endif // SCTOKENREPRESENTABLE_H
