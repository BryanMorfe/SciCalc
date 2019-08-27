#ifndef SCBINARYFUNCTION_H
#define SCBINARYFUNCTION_H

#include <functional>
#include "sctokenrepresentable.h"

class SCBinaryFunction : public SCTokenRepresentable
{
public:
    SCBinaryFunction(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, std::function<double(double, double)> &&eval);
    SCBinaryFunction(const SCBinaryFunction &other);

    const std::function<double(double, double)> evaluate;
};

#endif // SCBINARYFUNCTION_H
