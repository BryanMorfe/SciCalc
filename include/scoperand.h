#ifndef SCOPERAND_H
#define SCOPERAND_H

#include "sctokenrepresentable.h"

class SCOperand : public SCTokenRepresentable
{
public:
    SCOperand();
    SCOperand(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, double rv);
    SCOperand(const SCOperand &other);

    void setRawValue(double rv);

    double getRawValue() const;

private:
    double rawValue;
};

#endif // SCOPERAND_H
