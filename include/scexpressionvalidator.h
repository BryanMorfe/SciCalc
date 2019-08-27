#ifndef SCEXPRESSIONVALIDATOR_H
#define SCEXPRESSIONVALIDATOR_H

#include "scinexpression.h"

class SCExpressionValidator
{
public:
    SCExpressionValidator();

    bool validate(const SCInExpression &exp);

    static const SCExpressionValidator shared;
};

#endif // SCEXPRESSIONVALIDATOR_H
