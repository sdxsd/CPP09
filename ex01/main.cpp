#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2)
		return (1);
	try {
		std::cout << calculate(argv[1]) << std::endl;
	}
	catch (std::invalid_argument &ia) {
		std::cout << ia.what() << std::endl;
		return (1);
	}
}
