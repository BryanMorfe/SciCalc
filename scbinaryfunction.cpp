#include "scbinaryfunction.h"

SCBinaryFunction::SCBinaryFunction(const QString &tk, const SCTokenTypes::TokenType &tt, const QString &rep, std::function<double(double, double)> &&eval):
    SCTokenRepresentable (tk, tt, rep),
    evaluate(eval)
{}

SCBinaryFunction::SCBinaryFunction(const SCBinaryFunction &other):
    SCTokenRepresentable(other.token, other.type, other.tokenRepresentation),
    evaluate(other.evaluate)
{}
