#ifndef SCBINARYOPERATOR_H
#define SCBINARYOPERATOR_H

#include <functional>
#include "scoperator.h"

class SCBinaryOperator : public SCOperator
{
public:
    SCBinaryOperator(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep,
                     const SCTokenTypes::OperatorPrecedence &prec, const SCTokenTypes::OperatorAssociativity &assoc,
                     std::function<double(double, double)> &&eval);

    SCBinaryOperator(const SCBinaryOperator &other);

    const std::function<double(double, double)> evaluate;
};

#endif // SCBINARYOPERATOR_H
