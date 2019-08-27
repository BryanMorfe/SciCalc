#include "scevaluator.h"
#include <cmath>
#include <QStack>

#include "scoperand.h"
#include "scbinaryoperator.h"
#include "scunaryoperator.h"
#include "scunaryfunction.h"
#include "scbinaryfunction.h"
#include "sctokenoperations.h"

const SCEvaluator SCEvaluator::shared;

SCEvaluator::SCEvaluator() {}

SCInExpression SCEvaluator::evaluate(const SCParsedExpression &parsedExp)
{

    QList<SCToken> tokens = parsedExp.getTokens();
    QStack<SCOperand> resStack;

    for (auto token : tokens)
    {
        SCTokenTypes::TokenType type = token.getType();

        if (type == SCTokenTypes::operand)
        {
            SCOperand *newOperand = static_cast<SCOperand *>(SCTokenOperations::token(token.getToken()));
            resStack.push(*newOperand);
            delete newOperand;
        }
        else if (type == SCTokenTypes::unaryOperator)
        {
            SCUnaryOperator *unaryOperator = static_cast<SCUnaryOperator *>(SCTokenOperations::token(token.getToken()));
            SCOperand operandToken(resStack.pop());
            double operand = operandToken.getRawValue();
            double resultOperand = unaryOperator->evaluate(operand);
            delete unaryOperator;
            QString resultStr = QString::number(resultOperand);
            resStack.push(SCOperand(resultStr, SCTokenTypes::operand, resultStr, resultOperand));
        }
        else if (type == SCTokenTypes::binaryOperator)
        {
            SCBinaryOperator *binaryOperator = static_cast<SCBinaryOperator *>(SCTokenOperations::token(token.getToken()));
            SCOperand operandToken2(resStack.pop());
            SCOperand operandToken1(resStack.pop());
            double operand2 = operandToken2.getRawValue();
            double operand1 = operandToken1.getRawValue();
            double resultOperand = binaryOperator->evaluate(operand1, operand2);
            delete binaryOperator;
            QString resultStr = QString::number(resultOperand);
            resStack.push(SCOperand(resultStr, SCTokenTypes::operand, resultStr, resultOperand));
        }
        else if (type == SCTokenTypes::unaryFunction)
        {
            SCUnaryFunction *unaryFunction = static_cast<SCUnaryFunction *>(SCTokenOperations::token(token.getToken()));
            SCOperand operandToken(resStack.pop());
            double operand = operandToken.getRawValue();
            double resultOperand = unaryFunction->evaluate(operand);
            delete unaryFunction;
            QString resultStr = QString::number(resultOperand);
            resStack.push(SCOperand(resultStr, SCTokenTypes::operand, resultStr, resultOperand));
        }
        else if (type == SCTokenTypes::binaryFunction)
        {
            SCBinaryFunction *binaryFunction = static_cast<SCBinaryFunction *>(SCTokenOperations::token(token.getToken()));
            SCOperand operandToken2(resStack.pop());
            SCOperand operandToken1(resStack.pop());
            double operand2 = operandToken2.getRawValue();
            double operand1 = operandToken1.getRawValue();
            double resultOperand = binaryFunction->evaluate(operand1, operand2);
            delete binaryFunction;
            QString resultStr = QString::number(resultOperand);
            resStack.push(SCOperand(resultStr, SCTokenTypes::operand, resultStr, resultOperand));
        }
    }

    SCInExpression resultExpression;
    resultExpression.addToken(resStack.pop());

    return resultExpression;
}
