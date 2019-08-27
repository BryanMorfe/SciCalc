#include "scoperand.h"

SCOperand::SCOperand() {}

SCOperand::SCOperand(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, double rv):
    SCTokenRepresentable(tk, tt, rep),
    rawValue(rv)
{}

SCOperand::SCOperand(const SCOperand &other):
    SCTokenRepresentable (other.token, other.type, other.tokenRepresentation),
    rawValue(other.rawValue) {}

void SCOperand::setRawValue(double rv)
{
    rawValue = rv;
}

double SCOperand::getRawValue() const
{
    return rawValue;
}
