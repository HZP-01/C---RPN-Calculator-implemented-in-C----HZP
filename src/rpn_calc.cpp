#include <iostream>
#include <string>
#include "rpn_calculator.h"

void showHelp() {
    std::cout << "\n=== RPN计算器使用帮助 ===\n";
    std::cout << "基础使用:\n";
    std::cout << "  数字: 将数字压入栈 (例: 5, 3.14)\n";
    std::cout << "  操作符: 对栈顶元素进行运算\n";
    std::cout << "    + : 加法 (a b + → a+b)\n";
    std::cout << "    - : 减法 (a b - → a-b)\n";
    std::cout << "    * : 乘法 (a b * → a*b)\n";
    std::cout << "    / : 除法 (a b / → a/b)\n";
    
    std::cout << "\n栈操作:\n";
    std::cout << "  clear : 清空栈\n";
    std::cout << "  stack : 显示当前栈内容\n";
    
    std::cout << "\n高级功能:\n";
    std::cout << "  fib n : 计算第n个斐波那契数 (例: 10 fib)\n";
    std::cout << "  pascal n : 计算杨辉三角第n行的和 (例: 5 pascal)\n";
    
    std::cout << "\n示例:\n";
    std::cout << "  > 5 5 +           → 10\n";
    std::cout << "  > 1 2 + 3 + 7 7 * + → 55\n";
    std::cout << "  > 10 fib          → 55\n";
    std::cout << "  > 5 pascal        → 32\n";
    std::cout << "=======================\n\n";
}

int main() {
    RPNCalculator calc;
    std::string input;
    
    std::cout << "=== C++ RPN 计算器 ===\n";
    std::cout << "输入 'help' 查看命令, 'q' 退出程序\n\n";
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input == "q" || input == "quit" || input == "exit") {
            std::cout << "再见!" << std::endl;
            break;
        }
        
        if (input == "help" || input == "h") {
            showHelp();
            continue;
        }
        
        if (input.empty()) {
            continue;
        }
        
        try {
            double result = calc.processExpression(input);
            if (input != "stack" && input != "clear") {
                std::cout << "结果: " << result << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    return 0;
}
