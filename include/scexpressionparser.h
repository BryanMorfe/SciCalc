#ifndef SCEXPRESSIONPARSER_H
#define SCEXPRESSIONPARSER_H

#include "scinexpression.h"
#include "scparsedexpression.h"

class SCExpressionParser
{
public:
    SCExpressionParser();

    SCParsedExpression parse(const SCInExpression &exp);

    static const SCExpressionParser shared;
};

#endif // SCEXPRESSIONPARSER_H
