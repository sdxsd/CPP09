#include "RPN.hpp"

int (*operations[4])(int x, int y) {
	[](int x, int y) -> int {
		return (x + y);
	},
	[](int x, int y) -> int {
		return (x - y);
	},
	[](int x, int y) -> int {
		return (x / y);
	},
	[](int x, int y) -> int {
		return (x * y);
	}
};

operators isOperator(const std::string& token) {
	if (token == "+")
		return (PLUS);
	if (token == "-")
		return (MINUS);
	if (token == "*")
		return (TIMES);
	if (token == "/")
		return (DIVIDED);
	else
		return (INVALID);
}

int calculate(const std::string& expression) {
	std::istringstream stringStream(expression);
	std::stack<int> stack;
	std::string token;
	int x, y;
	for (int i = 0; i < expression.size(); i++) {
		stringStream >> token;
		if (token.size() < 2 && isOperator(token) != INVALID) {
			int x = stack.top();
			stack.pop();
			int y = stack.top();
			stack.pop();
			stack.push(operations[isOperator(token)](x, y));
		}
	}
}
