#ifndef SCOPERATOR_H
#define SCOPERATOR_H

#include "sctokenrepresentable.h"

class SCOperator : public SCTokenRepresentable
{
public:
    SCOperator(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep,
               const SCTokenTypes::OperatorPrecedence &prec, const SCTokenTypes::OperatorAssociativity &assoc);

    SCOperator(const SCOperator &other);

    void setPrecedence(const SCTokenTypes::OperatorPrecedence &prec);
    void setAssociativity(const SCTokenTypes::OperatorAssociativity &assoc);

    SCTokenTypes::OperatorPrecedence getPrecedence() const;
    SCTokenTypes::OperatorAssociativity getAssociativity() const;

protected:
    SCTokenTypes::OperatorPrecedence precedence;
    SCTokenTypes::OperatorAssociativity associativity;
};

#endif // SCOPERATOR_H
