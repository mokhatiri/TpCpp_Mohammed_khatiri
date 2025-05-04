#include "calculate.hpp"
#include "DivideByZeroException.hpp"
#include "InvalidOperationException.hpp"

double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw DivideByZeroException();
            return num1 / num2;
        default:
            throw InvalidOperationException();
    }
}