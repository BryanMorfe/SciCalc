#include "scinexpression.h"
#include "sctokenoperations.h"

#include <QDebug>

SCInExpression::SCInExpression() {}

QString SCInExpression::getPartialToken() const
{
    return partialToken;
}

bool SCInExpression::addPartialToken(const QChar &ch)
{
    bool successful;
    SCTokenTypes::TokenType type = SCTokenOperations::tokenType(ch);

    if (partialToken.isEmpty())
    {
        if (type == SCTokenTypes::partialOperand || type == SCTokenTypes::partialFunction)
        {
            partialToken = ch;
            lastTokenType = type;
            successful = true;
        }
        else if (type != unknown)
        {
            SCToken newToken(ch, type);
            tokens.append(newToken);
            successful = true;
        }
        else
            successful = false;
    }
    else
    {

        partialToken += ch;

        if (isPartialTokenFullToken())
        {
            SCTokenTypes::TokenType newType = SCTokenOperations::tokenType(partialToken);

            if (newType == SCTokenTypes::operand)
                partialToken += ch;
            else
            {
                SCToken newToken(partialToken, newType);
                partialToken.clear();
            }

            successful = true;

        }
        else
        {
            // Remove appended ch
            partialToken.remove(partialToken.size() - 1, 1);
            if (type != SCTokenTypes::unknown)
            {
                if (isPartialTokenFullToken())
                {
                    SCTokenTypes::TokenType newType = SCTokenOperations::tokenType(partialToken);
                    SCToken newToken(partialToken, newType);
                    partialToken = ch;
                    successful = true;
                }
                else
                    successful = false;
            }
            else
                successful = false;
        }
    }

    return successful;
}

bool SCInExpression::addStringToken(const QString &str)
{
    bool successful;

    if (partialToken.isEmpty())
    {
        // Add it to the list if it's a valid token
        SCTokenTypes::TokenType type = SCTokenOperations::tokenType(str);

        if (type != SCTokenTypes::unknown && type != SCTokenTypes::partialOperand && type != SCTokenTypes::partialFunction)
        {
            SCToken newToken(str, type);
            tokens.append(newToken);
            successful = true;
        }
        else
            successful = false;
    }
    else
    {
        // check if partialToken has become a full token
        if (isPartialTokenFullToken())
        {
            SCTokenTypes::TokenType partialTokenType = SCTokenOperations::tokenType(partialToken);
            SCToken newToken(partialToken, partialTokenType);
            tokens.append(newToken);
            partialToken.clear();
            successful = addStringToken(str);
        }
        else
            successful = false;
    }

    return successful;
}

void SCInExpression::delLastToken()
{
    if (!partialToken.isEmpty())
        partialToken.remove(partialToken.size() - 1, 1);
    else if (!tokens.isEmpty())
    {
        if (tokens.size() > 0)
        {
            SCToken lastToken = tokens.last();
            tokens.removeLast();
            partialToken = lastToken.getToken();
            partialToken.remove(partialToken.size() - 1, 1);

            SCTokenTypes::TokenType lastType = lastToken.getType();

            if (lastType == SCTokenTypes::operand)
                lastTokenType = SCTokenTypes::partialOperand;
            else if (lastType == SCTokenTypes::binaryFunction || lastType == SCTokenTypes::unaryFunction)
                lastTokenType = SCTokenTypes::partialFunction;
        }
    }
}

void SCInExpression::clear()
{
    tokens.clear();
    partialToken.clear();
}

bool SCInExpression::isPartialTokenFullToken() const
{
    SCTokenTypes::TokenType partialTokenType = SCTokenOperations::tokenType(partialToken);

    return partialTokenType != SCTokenTypes::unknown &&
           partialTokenType != SCTokenTypes::partialOperand &&
           partialTokenType != SCTokenTypes::partialFunction;
}

