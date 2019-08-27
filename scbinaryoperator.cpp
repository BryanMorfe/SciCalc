#include "scbinaryoperator.h"

SCBinaryOperator::SCBinaryOperator(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep,
                                   const SCTokenTypes::OperatorPrecedence &prec, const SCTokenTypes::OperatorAssociativity &assoc,
                                   std::function<double(double, double)> &&eval):
    SCOperator (tk, tt, rep, prec, assoc),
    evaluate(eval)
{}

SCBinaryOperator::SCBinaryOperator(const SCBinaryOperator &other):
    SCOperator(other.token, other.type, other.tokenRepresentation, other.precedence, other.associativity),
    evaluate(other.evaluate)
{}
