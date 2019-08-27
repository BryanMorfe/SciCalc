#ifndef SCPARSEDEXPRESSION_H
#define SCPARSEDEXPRESSION_H

#include "scexpression.h"

class SCParsedExpression : public SCExpression
{
public:
    SCParsedExpression();

    bool addStringToken(const QString &str);

};

#endif // SCPARSEDEXPRESSION_H
