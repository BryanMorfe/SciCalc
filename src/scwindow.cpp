#include "include/scwindow.h"
#include "ui_scwindow.h"
#include <QDebug>

#include "include/scexpressionvalidator.h"
#include "include/scevaluator.h"
#include "include/scexpressionparser.h"

SCWindow::SCWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SCWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // Setup Output
    outputDisplay = SCOutputDisplay(ui->expressionLabel, ui->messageLabel);

}

SCWindow::~SCWindow()
{
    delete ui;
}


void SCWindow::on_buttonZero_clicked()
{
    if (mainInExpression.addPartialToken('0'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 0");

}

void SCWindow::on_buttonDot_clicked()
{
    if (mainInExpression.addPartialToken('.'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: .");
}

void SCWindow::on_buttonOne_clicked()
{
    if (mainInExpression.addPartialToken('1'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 1");
}

void SCWindow::on_buttonTwo_clicked()
{
    if (mainInExpression.addPartialToken('2'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 2");
}

void SCWindow::on_buttonThree_clicked()
{
    if (mainInExpression.addPartialToken('3'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 3");
}

void SCWindow::on_buttonFour_clicked()
{
    if (mainInExpression.addPartialToken('4'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 4");
}

void SCWindow::on_buttonFive_clicked()
{
    if (mainInExpression.addPartialToken('5'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 5");
}

void SCWindow::on_buttonSix_clicked()
{
    if (mainInExpression.addPartialToken('6'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 6");
}

void SCWindow::on_buttonSeven_clicked()
{
    if (mainInExpression.addPartialToken('7'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 7");
}

void SCWindow::on_buttonEight_clicked()
{
    if (mainInExpression.addPartialToken('8'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 8");
}

void SCWindow::on_buttonNine_clicked()
{
    if (mainInExpression.addPartialToken('9'))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: 9");
}

void SCWindow::on_buttonClear_clicked()
{
    mainInExpression.clear();

    outputDisplay.output(mainInExpression);
}

void SCWindow::on_buttonDiv_clicked()
{
    if (mainInExpression.addStringToken("/"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: /");
}

void SCWindow::on_buttonMul_clicked()
{
    if (mainInExpression.addStringToken("*"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: *");
}

void SCWindow::on_buttonPlus_clicked()
{
    if (mainInExpression.addStringToken("+"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: +");
}

void SCWindow::on_buttonMinus_clicked()
{
    if (mainInExpression.addStringToken("-"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: -");
}

void SCWindow::on_buttonEqual_clicked()
{
    // Evaluate

    SCExpressionValidator validator = SCExpressionValidator::shared;

    if (validator.validate(mainInExpression))
    {
        SCExpressionParser parser = SCExpressionParser::shared;
        SCEvaluator evaluator = SCEvaluator::shared;

        store.saveInExpression(mainInExpression);

        SCParsedExpression parsedExp;

        parsedExp = parser.parse(mainInExpression);

        mainInExpression = evaluator.evaluate(parsedExp);

        outputDisplay.output(mainInExpression);
    }
    else
        outputDisplay.output("Invalid expression.");

}

void SCWindow::on_buttonDefine_clicked()
{
    mainInExpression.delLastToken();

    outputDisplay.output(mainInExpression);
}

void SCWindow::on_buttonFunc_clicked()
{

}

void SCWindow::on_buttonHistory_clicked()
{
    // Retrieve from store,
    // Present in a separate view
}

void SCWindow::on_buttonLPar_clicked()
{
    if (mainInExpression.addStringToken("("))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: (");
}

void SCWindow::on_buttonRPar_clicked()
{
    if (mainInExpression.addStringToken(")"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: )");
}

void SCWindow::on_buttonLBrac_clicked()
{
    if (mainInExpression.addStringToken("["))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: [");
}

void SCWindow::on_buttonRSBrac_clicked()
{
    if (mainInExpression.addStringToken("]"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: ]");
}

void SCWindow::on_buttonPi_clicked()
{
    if (mainInExpression.addStringToken("pi"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: pi");
}

void SCWindow::on_buttonNatLog_clicked()
{
    if (mainInExpression.addStringToken("ln"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: ln");
}

void SCWindow::on_buttonLog2_clicked()
{
    if (mainInExpression.addStringToken("log"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: log2");
}

void SCWindow::on_buttonLog10_clicked()
{
    if (mainInExpression.addStringToken("lg"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: log10");
}

void SCWindow::on_buttonLogN_clicked()
{
    if (mainInExpression.addStringToken("nlog"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: log");
}

void SCWindow::on_buttonEul_clicked()
{
    if (mainInExpression.addStringToken("e"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: e");
}

void SCWindow::on_buttonSqrt_clicked()
{
    if (mainInExpression.addStringToken("sqrt"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: sqrt");
}

void SCWindow::on_buttonRoot_clicked()
{
    if (mainInExpression.addStringToken("root"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: root");
}

void SCWindow::on_buttonPow_clicked()
{
    if (mainInExpression.addStringToken("^"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: ^");
}

void SCWindow::on_buttonFact_clicked()
{
    if (mainInExpression.addStringToken("!"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: !");
}

void SCWindow::on_buttonEE_clicked()
{
    if (mainInExpression.addStringToken("E"))
        outputDisplay.output(mainInExpression);
    else
        outputDisplay.output("Invalid token: E");
}

void SCWindow::on_buttonSin_clicked()
{

}

void SCWindow::on_buttonCos_clicked()
{

}

void SCWindow::on_buttonTan_clicked()
{

}

void SCWindow::on_buttonMin_clicked()
{

}

void SCWindow::on_buttonMax_clicked()
{

}

void SCWindow::on_buttonAsin_clicked()
{

}

void SCWindow::on_buttonAcos_clicked()
{

}

void SCWindow::on_buttonAtan_clicked()
{

}

void SCWindow::on_buttonBin_clicked()
{

}

void SCWindow::on_buttonHex_clicked()
{

}

void SCWindow::keyPressEvent(QKeyEvent *event)
{
    QChar key = event->text().front();

    qDebug() << key;

    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)
    {
        mainInExpression.delLastToken();
        outputDisplay.output(mainInExpression);
    }
    else if (key == '=' || key == '\r' || key == '\n')
    {
        SCExpressionValidator validator = SCExpressionValidator::shared;

        if (validator.validate(mainInExpression))
        {
            SCExpressionParser parser = SCExpressionParser::shared;
            SCEvaluator evaluator = SCEvaluator::shared;

            store.saveInExpression(mainInExpression);

            SCParsedExpression parsedExp;

            parsedExp = parser.parse(mainInExpression);

            mainInExpression = evaluator.evaluate(parsedExp);

            outputDisplay.output(mainInExpression);
        }
        else
            outputDisplay.output("Invalid expression.");
    }
    else if (key != '\0')
    {
        if (mainInExpression.addPartialToken(key))
            outputDisplay.output(mainInExpression);
        else
            outputDisplay.output("Invalid token: " + QString(key));
    }
    else
        QWidget::keyPressEvent(event);

}
