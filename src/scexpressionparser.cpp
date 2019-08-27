#include "include/scexpressionparser.h"

#include <QStack>
#include <QDebug>

#include "include/sctokenoperations.h"

const SCExpressionParser SCExpressionParser::shared;

SCExpressionParser::SCExpressionParser() {}

SCParsedExpression SCExpressionParser::parse(const SCInExpression &exp)
{

    QStack<SCToken> opStack;
    SCParsedExpression parsedExp;
    QList<SCToken> tokens = exp.getTokens();

    QString partialToken = exp.getPartialToken();

    if (!partialToken.isEmpty())
    {
        SCToken *tokenFromPartial = SCTokenOperations::token(exp.getPartialToken());
        tokens.append(*tokenFromPartial);
        delete tokenFromPartial;
    }

    for (auto token : tokens)
    {
        SCTokenTypes::TokenType type = token.getType();

        if (type == SCTokenTypes::operand)
            parsedExp.addToken(token);
        else if (type == SCTokenTypes::lParenthesis)
            opStack.push(token);
        else if (type == SCTokenTypes::rParenthesis)
        {
            SCToken topOp(opStack.pop());
            while (topOp.getType() != SCTokenTypes::lParenthesis)
            {
                parsedExp.addToken(topOp);
                topOp = opStack.pop();
            }
        }
        else if (type == SCTokenTypes::lBracket)
            opStack.push(token);
        else if (type == SCTokenTypes::rBracket)
        {
            SCToken topOp(opStack.pop());
            while (topOp.getType() != SCTokenTypes::lBracket)
            {
                parsedExp.addToken(topOp);
                topOp = opStack.pop();
            }
        }
        else if (type == SCTokenTypes::unaryOperator || type == SCTokenTypes::binaryOperator)
        {
            SCOperator *newOp = static_cast<SCOperator *>(SCTokenOperations::token(token.getToken()));

            bool shouldLook = true;
            while (shouldLook && !opStack.isEmpty())
            {
                SCOperator *topOp = static_cast<SCOperator *>(SCTokenOperations::token(opStack.top().getToken()));

                if ((topOp->getType() == binaryOperator || topOp->getType() == unaryOperator) &&
                        newOp->getPrecedence() <= topOp->getPrecedence())
                {
                    opStack.pop();
                    parsedExp.addToken(*topOp);
                    delete topOp;
                    if (!opStack.isEmpty())
                        topOp = static_cast<SCOperator *>(SCTokenOperations::token(opStack.top().getToken()));
                }
                else
                    shouldLook = false;

            }

            opStack.push(*newOp);
            delete newOp;
        }
    }

    while (!opStack.isEmpty())
        parsedExp.addToken(opStack.pop());

    return parsedExp;
}
