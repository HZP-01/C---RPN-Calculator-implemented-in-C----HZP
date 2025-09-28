import nimib

nbInit
nbText: """
# RPN计算器 - 使用说明文档

## 项目简介
这是一个基于C++实现的逆波兰表示法计算器，支持基础四则运算和高级数学功能。

## 安装和编译
```bash
cd ~/Work/rpn_calc
make
```

## 基本使用
```bash
./rpn_calc
```

## 支持的操作
- 四则运算: + - * /
- 栈操作: clear, stack
- 高级功能: fib, pascal

## 示例
```
> 1 2 + 3 + 7 7 * +
结果: 55
> 10 fib
结果: 55
> 5 pascal
结果: 32
```
"""

nbSave
