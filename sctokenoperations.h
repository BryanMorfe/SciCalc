#ifndef SCTOKENOPERATIONS_H
#define SCTOKENOPERATIONS_H

#include <QHash>
#include <cmath>

#include "scoperand.h"
#include "scoperator.h"
#include "sctokenrepresentable.h"
#include "scunaryoperator.h"
#include "scbinaryoperator.h"
#include "scunaryfunction.h"
#include "scbinaryfunction.h"

using namespace SCTokenTypes;

namespace SCTokenOperations
{
    static const QHash<QString, SCToken *> tokens({
        // Operators
        {"^", new SCBinaryOperator("^", binaryOperator, "^", highest, rightToLeft, [](double a, double b) -> double { return pow(a, b); })},
        {"!", new SCUnaryOperator("!", unaryOperator, "!", highest, leftToRight, [](double a) -> double { double res = 1; for (int i = 2; i <= a; i++) res *= i; return res; })},
        {"E", new SCBinaryOperator("E", binaryOperator, "E", high, leftToRight, [](double a, double b) -> double { return a * pow(10, b); })},
        {"*", new SCBinaryOperator("*", binaryOperator, " × ", high, leftToRight, [](double a, double b) -> double { return a * b; })},
        {"/", new SCBinaryOperator("/", binaryOperator, " ÷ ", high, leftToRight, [](double a, double b) -> double { return a / b; })},
        // {"%", new SCBinaryOperator("%", binaryOperator, "%", high, leftToRight, [](double a, double b) -> double { return a / b; })},
        {"+", new SCBinaryOperator("+", binaryOperator, " + ", medium, leftToRight, [](double a, double b) -> double { return a + b; })},
        {"-", new SCBinaryOperator("-", binaryOperator, " – ", medium, leftToRight, [](double a, double b) -> double { return a - b; })},

        // Operands
        {"pi", new SCOperand("pi", operand, "π", M_PI)},
        {"e", new SCOperand("e", operand, "e", exp(1.0))},

        // Functions
        {"log2", new SCUnaryFunction("log2", unaryFunction, "<em>log<sub>2</sub></em>", [](double a) -> double { return log2(a); })},
        {"log10", new SCUnaryFunction("log10", unaryFunction, "<em>log<sub>10</sub></em>", [](double a) -> double { return log10(a); })},
        {"ln", new SCUnaryFunction("ln", unaryFunction, "<em>ln</em>", [](double a) -> double { return log(a); })},
        {"logn", new SCBinaryFunction("logn", binaryFunction, "<em>log<sub>n</sub></em>", [](double a, double b) -> double { return log(a) / log(b); })},
        {"sqrt", new SCUnaryFunction("sqrt", unaryFunction, "<em>sqrt</em>", [](double a) -> double { return sqrt(a); })},
        {"root", new SCBinaryFunction("root", binaryFunction, "<em>root</em>", [](double a, double b) -> double { return pow(a, 1.0 / b); })},
        {"pow", new SCBinaryFunction("pow", binaryFunction, "<em>pow</em>", [](double a, double b) -> double { return pow(a, b); })},
        {"sin", new SCUnaryFunction("sin", unaryFunction, "<em>sin</em>", [](double a) -> double { return sin(a); })},
        {"cos", new SCUnaryFunction("cos", unaryFunction, "<em>cos</em>", [](double a) -> double { return cos(a); })},
        {"tan", new SCUnaryFunction("tan", unaryFunction, "<em>tan</em>", [](double a) -> double { return tan(a); })},
        {"asin", new SCUnaryFunction("asin", unaryFunction, "<em>asin</em>", [](double a) -> double { return asin(a); })},
        {"acos", new SCUnaryFunction("acos", unaryFunction, "<em>acos</em>", [](double a) -> double { return acos(a); })},
        {"atan", new SCUnaryFunction("atan", unaryFunction, "<em>atan</em>", [](double a) -> double { return atan(a); })},
        {"max", new SCBinaryFunction("max", binaryFunction, "<em>max</em>", [](double a, double b) -> double { return std::max(a, b); })},
        {"min", new SCBinaryFunction("min", binaryFunction, "<em>min</em>", [](double a, double b) -> double { return std::min(a, b); })},
        {"bin", new SCUnaryFunction("bin", unaryFunction, "<em>bin</em>", [](double a) -> double { return a; })},
        {"hex", new SCUnaryFunction("hex", unaryFunction, "<em>hex</em>", [](double a) -> double { return a; })},
        {"deg", new SCUnaryFunction("deg", unaryFunction, "<em>deg</em>", [](double a) -> double { return a * 180 / M_PI; })},
        {"rad", new SCUnaryFunction("rad", unaryFunction, "<em>rad</em>", [](double a) -> double { return a * M_PI / 180; })},

        // Special Tokens
        {"(", new SCToken("(", lParenthesis)},
        {")", new SCToken(")", rParenthesis)},
        {"[", new SCToken("[", lBracket)},
        {"]", new SCToken("]", rBracket)},
        {",", new SCToken(",", separator)},
        {".", new SCToken(".", partialOperand)},
    });

    TokenType tokenType(const QString &str);
    TokenType tokenType(const QChar &ch);
    SCToken *token(const QString &str);

}

#endif // SCTOKENOPERATIONS_H
