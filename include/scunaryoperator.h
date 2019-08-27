#ifndef SCUNARYOPERATOR_H
#define SCUNARYOPERATOR_H

#include <functional>
#include "scoperator.h"

class SCUnaryOperator : public SCOperator
{
public:
    SCUnaryOperator(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep,
                    const SCTokenTypes::OperatorPrecedence &prec, const SCTokenTypes::OperatorAssociativity &assoc,
                    std::function<double(double)> &&eval);
    SCUnaryOperator(const SCUnaryOperator &other);

    const std::function<double(double)> evaluate;
};

#endif // SCUNARYOPERATOR_H
