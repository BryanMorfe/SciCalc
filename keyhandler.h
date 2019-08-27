#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <QWidget>

class KeyHandler : public QWidget
{
    Q_OBJECT
public:
    KeyHandler();

private:
    void keyEventPress()
};

#endif // KEYHANDLER_H
