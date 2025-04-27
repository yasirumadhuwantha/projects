#include "calculator.h"
#include "./ui_calculator.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));

    // Connect number buttons (0-9)
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; i++) {
        QString butName = "Button" + QString::number(i);
        numButtons[i] = findChild<QPushButton *>(butName);
        if (numButtons[i]) {
            connect(numButtons[i], &QPushButton::released, this, &Calculator::NumPressed);
        }
    }

    // Connect Math buttons
    connect(ui->Add, &QPushButton::released, this, &Calculator::MathButtonPressed);
    connect(ui->Subtract, &QPushButton::released, this, &Calculator::MathButtonPressed);
    connect(ui->Multiply, &QPushButton::released, this, &Calculator::MathButtonPressed);
    connect(ui->Divide, &QPushButton::released, this, &Calculator::MathButtonPressed);

    // Connect Equal button
    connect(ui->Equal, &QPushButton::released, this, &Calculator::EqualButton);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return; // extra safety

    QString butVal = button->text();
    QString displayVal = ui->Display->text();

    if ((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)) {
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void Calculator::MathButtonPressed()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();

    // Trigger respective operation
    if (butVal == "+") {
        addTrigger = true;
    } else if (butVal == "-") {
        subTrigger = true;
    } else if (butVal == "*") {
        multTrigger = true;
    } else if (butVal == "/") {
        divTrigger = true;
    }

    ui->Display->setText("0"); // Reset display for next number input
}

void Calculator::EqualButton()
{
    double num2 = ui->Display->text().toDouble();
    double result = 0;

    if (addTrigger) {
        result = calcVal + num2;
        addTrigger = false;
    } else if (subTrigger) {
        result = calcVal - num2;
        subTrigger = false;
    } else if (multTrigger) {
        result = calcVal * num2;
        multTrigger = false;
    } else if (divTrigger) {
        if (num2 != 0) {
            result = calcVal / num2;
        } else {
            ui->Display->setText("Error! Division by zero");
            return;
        }
        divTrigger = false;
    }

    ui->Display->setText(QString::number(result));
}
