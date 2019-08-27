#ifndef SCOUTPUTDISPLAY_H
#define SCOUTPUTDISPLAY_H

#include <QLabel>
#include "scinexpression.h"

class SCOutputDisplay
{
public:
    SCOutputDisplay();
    SCOutputDisplay(QLabel *outLabel, QLabel *msgLabel);

    void output(const SCInExpression &inExp);
    void output(const QString &str);

    SCOutputDisplay &operator=(SCOutputDisplay &&other);

private:
    QLabel *outputLabel;
    QLabel *messageLabel;
};

#endif // SCOUTPUTDISPLAY_H
