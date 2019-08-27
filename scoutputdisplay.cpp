#include "scoutputdisplay.h"
#include "sctokenrepresentable.h"
#include "sctokenoperations.h"

SCOutputDisplay::SCOutputDisplay(): outputLabel(nullptr), messageLabel(nullptr) {}

SCOutputDisplay::SCOutputDisplay(QLabel *outLabel, QLabel *msgLabel): outputLabel(outLabel), messageLabel(msgLabel) {}

void SCOutputDisplay::output(const SCInExpression &inExp)
{
    QList<SCToken> tokens = inExp.getTokens();
    QString partialToken = inExp.getPartialToken();
    QString expression;

    for (auto token : tokens)
    {
        SCTokenTypes::TokenType type = token.getType();

        if (type == SCTokenTypes::operand || type == SCTokenTypes::unaryOperator || type == SCTokenTypes::binaryOperator ||
            type == SCTokenTypes::unaryFunction || type == SCTokenTypes::binaryFunction)
        {
            SCTokenRepresentable *representable = static_cast<SCTokenRepresentable *>(SCTokenOperations::token(token.getToken()));
            expression += representable->getRepresentation();
            delete representable;
        }
        else
            expression += token.getToken();
    }

    outputLabel->setText(expression + partialToken);
}

void SCOutputDisplay::output(const QString &str)
{
    messageLabel->setText(str);
}

SCOutputDisplay &SCOutputDisplay::operator=(SCOutputDisplay &&other)
{
    outputLabel = other.outputLabel;
    messageLabel = other.messageLabel;

    return *this;
}
