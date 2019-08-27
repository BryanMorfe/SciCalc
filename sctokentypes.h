#ifndef SCTOKENTYPES_H
#define SCTOKENTYPES_H

namespace SCTokenTypes
{
    enum TokenType
    {
        operand,
        partialOperand,
        unaryOperator,
        binaryOperator,
        unaryFunction,
        binaryFunction,
        partialFunction,
        lParenthesis,
        rParenthesis,
        lBracket,
        rBracket,
        separator,
        unknown
    };

    enum OperatorPrecedence : int
    {
        highest = 3,
        high = 2,
        medium = 1,
        low = 0
    };

    enum OperatorAssociativity
    {
        rightToLeft,
        leftToRight
    };

}

#endif // SCTOKENTYPES_H
