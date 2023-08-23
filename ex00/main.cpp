#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Invalid arguments to program." << std::endl;
		return (1);
	}
	std::ifstream dbFile("data.csv");
	std::ifstream inputFile(argv[1]);
	if (dbFile.fail()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return (1);
	}
	else if (inputFile.fail()) {
		std::cerr << "Error: could not open \"" << argv[1] << "\"" << std::endl;
		return (1);
	}
	BitcoinExchange exchange(dbFile);
	exchange.parseInput(inputFile);
}
