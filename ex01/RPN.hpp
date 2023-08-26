#ifndef RPN_H
#define RPN_H

#include <stack>
#include <string>
#include <sstream>
#include <limits>
#include <iostream>

enum operators {
	PLUS,
	MINUS,
	TIMES,
	DIVIDED,
	INVALID
};

int calculate(const std::string& expression);

#endif // RPN_H
