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
	switch (token[0]) {
		case '+': return (PLUS);
		case '-': return (MINUS);
		case '/': return (DIVIDED);
		case '*': return (TIMES);
	}
	return (INVALID);
}

int topAndPop(std::stack<int>& stack) {
	int x = stack.top();
	stack.pop();
	return (x);
}

void combineAndPush(std::stack<int>& stack, int (*opFunc)(int, int)) {
	stack.push(opFunc(topAndPop(stack), topAndPop(stack)));
}

int calculate(const std::string& expression) {
	std::istringstream stringStream(expression);
	std::stack<int> stack;
	std::string token;

	while (stringStream >> token) {
		if (token.size() < 2 && isOperator(token) != INVALID)
			combineAndPush(stack, operations[isOperator(token)]);
		else if (stoi(token) < 10)
			stack.push(stoi(token));
	}
	while (stack.size() > 0)
		std::cout << topAndPop(stack) << std::endl;
	return (0);
}
