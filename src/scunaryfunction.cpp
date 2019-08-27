#include "include/scunaryfunction.h"

SCUnaryFunction::SCUnaryFunction(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, std::function<double(double)> &&eval):
    SCTokenRepresentable(tk, tt, rep),
    evaluate(eval)
{}

SCUnaryFunction::SCUnaryFunction(const SCUnaryFunction &other):
    SCTokenRepresentable (other.token, other.type, other.tokenRepresentation),
    evaluate(other.evaluate)
{}
