#ifndef SCUNARYFUNCTION_H
#define SCUNARYFUNCTION_H

#include <functional>
#include "sctokenrepresentable.h"

class SCUnaryFunction : public SCTokenRepresentable
{
public:
    SCUnaryFunction(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, std::function<double(double)> &&eval);
    SCUnaryFunction(const SCUnaryFunction &other);

    const std::function<double(double)> evaluate;
};

#endif // SCUNARYFUNCTION_H
