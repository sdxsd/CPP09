#include "RPN.hpp"

int (*operations[4])(int x, int y) {
	[](int x, int y) -> int {
		return (x + y);
	},
	[](int x, int y) -> int {
		return (x - y);
	},
	[](int x, int y) -> int {
		return (x * y);
	},
	[](int x, int y) -> int {
		return (x / y);
	}
};

operators typeOperator(const std::string& token) {
	switch (token[0]) {
		case '+': return (PLUS);
		case '-': return (MINUS);
		case '*': return (TIMES);
		case '/': return (DIVIDED);
	}
	return (INVALID);
}

int topAndPop(std::stack<int>& stack) {
	int	x = stack.top();
	stack.pop();
	return (x);
}

void combineAndPush(std::stack<int>& stack, int (*opFunc)(int, int)) {
	stack.push(opFunc(topAndPop(stack), topAndPop(stack)));
}

int calculate(const std::string& expression) {
	std::istringstream	stringStream(expression);
	std::stack<int> 	stack;
	std::string 		token;

	while (stringStream >> token) {
		if (typeOperator(token) != INVALID && stack.size() > 1 && token.size() == 1)
			combineAndPush(stack, operations[typeOperator(token)]);
		else if (isdigit(token[0]) && token.size() == 1)
			stack.push(stoi(token));
		else
			throw std::invalid_argument("Error");
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Error");
	return (stack.top());
}
