#ifndef SCWINDOW_H
#define SCWINDOW_H

#include <QMainWindow>

#include "scinexpression.h"
#include "scoutputdisplay.h"
#include "scstore.h"

namespace Ui {
class SCWindow;
}

class SCWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SCWindow(QWidget *parent = nullptr);
    ~SCWindow();

private slots:
    void on_buttonZero_clicked();

    void on_buttonDot_clicked();

    void on_buttonOne_clicked();

    void on_buttonTwo_clicked();

    void on_buttonSeven_clicked();

    void on_buttonThree_clicked();

    void on_buttonFour_clicked();

    void on_buttonFive_clicked();

    void on_buttonSix_clicked();

    void on_buttonEight_clicked();

    void on_buttonNine_clicked();

    void on_buttonClear_clicked();

    void on_buttonDiv_clicked();

    void on_buttonMul_clicked();

    void on_buttonPlus_clicked();

    void on_buttonMinus_clicked();

    void on_buttonEqual_clicked();

    void on_buttonDefine_clicked();

    void on_buttonFunc_clicked();

    void on_buttonHistory_clicked();

    void on_buttonLPar_clicked();

    void on_buttonRPar_clicked();

    void on_buttonLBrac_clicked();

    void on_buttonRSBrac_clicked();

    void on_buttonPi_clicked();

    void on_buttonNatLog_clicked();

    void on_buttonLog2_clicked();

    void on_buttonLog10_clicked();

    void on_buttonLogN_clicked();

    void on_buttonEul_clicked();

    void on_buttonSqrt_clicked();

    void on_buttonRoot_clicked();

    void on_buttonPow_clicked();

    void on_buttonFact_clicked();

    void on_buttonEE_clicked();

    void on_buttonSin_clicked();

    void on_buttonCos_clicked();

    void on_buttonTan_clicked();

    void on_buttonMin_clicked();

    void on_buttonMax_clicked();

    void on_buttonAsin_clicked();

    void on_buttonAcos_clicked();

    void on_buttonAtan_clicked();

    void on_buttonBin_clicked();

    void on_buttonHex_clicked();

private:
    void keyPressEvent(QKeyEvent *event);

private:

    Ui::SCWindow *ui;
    SCInExpression mainInExpression;
    SCOutputDisplay outputDisplay;
    SCStore store;
};

#endif // SCWINDOW_H
