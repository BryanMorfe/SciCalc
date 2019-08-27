#ifndef SCTOKEN_H
#define SCTOKEN_H

#include <QString>
#include "sctokentypes.h"

class SCToken
{
public:
    SCToken();
    SCToken(const QString &tk, const SCTokenTypes::TokenType &tt);
    SCToken(const SCToken &other);

    void setToken(const QString &tk);
    void setType(const SCTokenTypes::TokenType &tt);

    QString getToken() const;
    SCTokenTypes::TokenType getType() const;
protected:
    QString token;
    SCTokenTypes::TokenType type;
};

/*

namespace SCToken {

    enum OPAssoc: int
    {
        leftToRight,
        rightToLeft,
        invalidAssoc = -1
    };

    enum OPType: int
    {
        unary,
        binary,
        invalidType = -1
    };

    enum OPPrecedence: int
    {
        highest = 3,
        high = 2,
        medium = 1,
        low = 0,
        invalidPrecedence = -1
    };

    enum TokenType: int
    {
        operatr,
        operand,
        func,
        argSeparator,
        invalid = -1
    };

    struct SCOperator
    {
        SCOperator();
        SCOperator(const QString &o, OPAssoc assoc, OPType tp, OPPrecedence prec);

        QString op;
        OPAssoc associativity;
        OPType type;
        OPPrecedence precedence;
    };

    static const QHash<QString, SCOperator> operators({
        {"^", SCOperator("^", rightToLeft, binary, highest)},
        {"!", SCOperator("!", leftToRight, unary, highest)},
        {"*", SCOperator("*", leftToRight, binary, high)},
        {"/", SCOperator("/", leftToRight, binary, high)},
        {"%", SCOperator("%", leftToRight, binary, high)},
        {"+", SCOperator("+", leftToRight, binary, medium)},
        {"-", SCOperator("-", leftToRight, binary, medium)},
        {"(", SCOperator("(", leftToRight, binary, low)},
        {")", SCOperator(")", leftToRight, binary, low)}
    });

    static const QSet<QString> functions({
        "log", "ln", "e", "sqrt", "root", "pow",
        "sin", "cos", "tan", "asin", "acos", "atan",
        "max", "min", "bin", "hex", "deg", "rad"
    });

    static const QString _argSeparator = ",";

    TokenType tokenType(const QString &str);
    TokenType tokenType(const QChar &ch);

    SCOperator scOperator(const QString &str);
}


*/

#endif // SCTOKEN_H
