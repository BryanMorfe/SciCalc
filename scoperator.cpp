#include "scoperator.h"

SCOperator::SCOperator(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep,
                       const SCTokenTypes::OperatorPrecedence &prec, const SCTokenTypes::OperatorAssociativity &assoc):
    SCTokenRepresentable (tk, tt, rep),
    precedence(prec),
    associativity(assoc)
{}

SCOperator::SCOperator(const SCOperator &other):
    SCTokenRepresentable (other.token, other.type, other.tokenRepresentation),
    precedence(other.precedence),
    associativity(other.associativity)
{}

void SCOperator::setPrecedence(const SCTokenTypes::OperatorPrecedence &prec)
{
    precedence = prec;
}

void SCOperator::setAssociativity(const SCTokenTypes::OperatorAssociativity &assoc)
{
    associativity = assoc;
}

SCTokenTypes::OperatorPrecedence SCOperator::getPrecedence() const
{
    return precedence;
}

SCTokenTypes::OperatorAssociativity SCOperator::getAssociativity() const
{
    return associativity;
}
