#include "include/sctokenoperations.h"
#include <QRegularExpression>

TokenType SCTokenOperations::tokenType(const QChar &ch)
{
    TokenType type;
    QHash<QString, SCToken *>::const_iterator it = tokens.find(ch);

    if (it != tokens.end())
        type = it.value()->getType();
    else
    {
        if (ch.isLetter())
            type = partialFunction;
        else if (ch.isDigit() || ch == '.')
            type = partialOperand;
        else
            type = unknown;

    }

    return type;
}

TokenType SCTokenOperations::tokenType(const QString &str)
{
    TokenType type;
    QHash<QString, SCToken *>::const_iterator it = tokens.find(str);

    if (it != tokens.end())
        type = it.value()->getType();
    else
    {
        // check if it's operand
        /* Valid operands are:
         * Integers: 5, 6, 7, 5., 7., 3. (with no leading zeroes): [1-9][0-9]*\.?
         * Floats: .5, .7, 5.2, 5.0, 0.04, (multiple leading zeroes before the decimal point are allowed): [0-9]*\.[0-9]+
        */
        QRegularExpression regExp("([1-9][0-9]*\\.?)|([0-9]*\\.[0-9]+)");

        QRegularExpressionMatch match = regExp.match(str);
        if (match.hasMatch())
            type = operand;
        else
            type = unknown;

    }

    return type;
}

SCToken *SCTokenOperations::token(const QString &str)
{
    SCToken *token;
    QHash<QString, SCToken *>::const_iterator it = tokens.find(str);

    if (it != tokens.end())
    {
        SCToken *retrievedToken = it.value();

        switch (retrievedToken->getType())
        {
        case operand:
            token = new SCOperand(*static_cast<SCOperand *>(retrievedToken));
            break;
        case binaryOperator:
            token = new SCBinaryOperator(*static_cast<SCBinaryOperator *>(retrievedToken));
            break;
        case unaryOperator:
            token = new SCUnaryOperator(*static_cast<SCUnaryOperator *>(retrievedToken));
            break;
        case binaryFunction:
            token = new SCBinaryFunction(*static_cast<SCBinaryFunction *>(retrievedToken));
            break;
        case unaryFunction:
            token = new SCUnaryFunction(*static_cast<SCUnaryFunction *>(retrievedToken));
            break;
        case lParenthesis:
        case rParenthesis:
        case lBracket:
        case rBracket:
        case separator:
            token = new SCToken(*retrievedToken);
            break;
        default:
            token = nullptr;
        }
    }
    else
    {
        TokenType type = tokenType(str);
        if (type == operand)
            token = new SCOperand(str, operand, str, str.toDouble());
        else
            token = nullptr;
    }

    return token;

}


