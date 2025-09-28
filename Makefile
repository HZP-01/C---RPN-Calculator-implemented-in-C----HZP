CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
TARGET = rpn_calc
SRCDIR = src
SOURCES = $(SRCDIR)/rpn_calc.cpp $(SRCDIR)/rpn_calculator.cpp
HEADERS = $(SRCDIR)/rpn_calculator.h

$(TARGET): $(SOURCES) $(HEADERS)
	@echo "编译RPN计算器..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)
	@echo "编译完成！可执行文件: $(TARGET)"

clean:
	@echo "清理生成文件..."
	rm -f $(TARGET)
	rm -f *.html
	@echo "清理完成！"

run: $(TARGET)
	@echo "启动RPN计算器..."
	./$(TARGET)

.PHONY: clean run
