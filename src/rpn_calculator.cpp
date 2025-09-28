#include "rpn_calculator.h"
#include <vector>
#include <sstream>
#include <cctype>

bool RPNCalculator::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/" ||
           token == "fib" || token == "pascal";
}

bool RPNCalculator::isNumber(const std::string& token) const {
    std::istringstream iss(token);
    double d;
    char c;
    return (iss >> d) && !(iss >> c);
}

void RPNCalculator::push(double value) {
    stack.push(value);
}

double RPNCalculator::pop() {
    if (stack.empty()) {
        throw CalculationError("错误: 栈为空");
    }
    double value = stack.top();
    stack.pop();
    return value;
}

void RPNCalculator::clear() {
    while (!stack.empty()) {
        stack.pop();
    }
}

void RPNCalculator::displayStack() const {
    if (stack.empty()) {
        std::cout << "栈: [空]" << std::endl;
        return;
    }

    std::stack<double> temp = stack;
    std::vector<double> elements;

    while (!temp.empty()) {
        elements.push_back(temp.top());
        temp.pop();
    }

    std::cout << "栈: ";
    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void RPNCalculator::handleOperator(const std::string& op) {
    if (op == "fib") {
        if (stack.empty()) throw CalculationError("错误: fib需要参数");
        int n = static_cast<int>(pop());
        fibonacci(n);
        return;
    }

    if (op == "pascal") {
        if (stack.empty()) throw CalculationError("错误: pascal需要参数");
        int n = static_cast<int>(pop());
        pascalsTriangle(n);
        return;
    }

    if (stack.size() < 2) {
        throw CalculationError("错误: 操作符 '" + op + "' 需要两个操作数");
    }

    double b = pop();
    double a = pop();
    double result;

    if (op == "+") {
        result = a + b;
    } else if (op == "-") {
        result = a - b;
    } else if (op == "*") {
        result = a * b;
    } else if (op == "/") {
        if (b == 0) {
            throw CalculationError("错误: 除零错误");
        }
        result = a / b;
    } else {
        throw CalculationError("错误: 未知操作符 '" + op + "'");
    }

    push(result);
}

void RPNCalculator::fibonacci(int n) {
    if (n < 0) {
        throw CalculationError("错误: 斐波那契数列需要非负整数");
    }

    if (n == 0) {
        push(0);
        return;
    }

    if (n == 1) {
        push(1);
        return;
    }

    double a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        double temp = a + b;
        a = b;
        b = temp;
    }
    push(b);
}

void RPNCalculator::pascalsTriangle(int n) {
    if (n < 0) {
        throw CalculationError("错误: 杨辉三角需要非负整数");
    }

    double sum = std::pow(2, n);
    push(sum);
}

double RPNCalculator::processExpression(const std::string& expression) {
    if (expression.empty()) {
        throw CalculationError("错误: 空表达式");
    }

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "clear") {
            clear();
            std::cout << "栈已清空" << std::endl;
            return 0;
        } else if (token == "stack") {
            displayStack();
            return stack.empty() ? 0 : stack.top();
        } else if (isNumber(token)) {
            push(std::stod(token));
        } else if (isOperator(token)) {
            calculate(token);
        } else {
            throw CalculationError("错误: 未知token '" + token + "'");
        }
    }

    if (stack.empty()) {
        throw CalculationError("错误: 没有结果");
    }

    return stack.top();
}

void RPNCalculator::calculate(const std::string& operation) {
    handleOperator(operation);
}
