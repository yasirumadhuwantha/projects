#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
