#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <iostream>

class RPNCalculator {
private:
    std::stack<double> stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    void handleOperator(const std::string& op);

public:
    void push(double value);
    double pop();
    void clear();
    void displayStack() const;

    double processExpression(const std::string& expression);
    void calculate(const std::string& operation);

    void fibonacci(int n);
    void pascalsTriangle(int n);

    class CalculationError : public std::runtime_error {
    public:
        CalculationError(const std::string& msg) : std::runtime_error(msg) {}
    };
};

#endif
