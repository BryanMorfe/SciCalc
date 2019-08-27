#include "scparsedexpression.h"
#include "sctokenoperations.h"

SCParsedExpression::SCParsedExpression() {}

bool SCParsedExpression::addStringToken(const QString &str)
{
    bool successful;
    SCTokenTypes::TokenType type = SCTokenOperations::tokenType(str);

    if (type != unknown && type != partialOperand && type != partialFunction)
    {
        tokens.append(SCToken(str, type));
        successful = true;
    }
    else
        successful = false;

    return successful;
}
