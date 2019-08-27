#include "include/scexpressionvalidator.h"

const SCExpressionValidator SCExpressionValidator::shared;

SCExpressionValidator::SCExpressionValidator() {}

bool SCExpressionValidator::validate(const SCInExpression &exp)
{
    return true;
}
