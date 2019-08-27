#ifndef SCEVALUATOR_H
#define SCEVALUATOR_H

#include "scexpression.h"
#include "scinexpression.h"
#include "scparsedexpression.h"
//#include <scfunction.h>

class SCEvaluator
{
public:
    SCEvaluator();

    SCInExpression evaluate(const SCParsedExpression &parsedExp);

    static const SCEvaluator shared;

};

#endif // SCEVALUATOR_H
