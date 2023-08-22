#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2)
		std::cout << "Invalid arguments to program." << std::endl;
	std::ifstream dbFile("data.csv");
	std::ifstream inputFile(argv[1]);
	BitcoinExchange exchange(dbFile);
	exchange.parseInput(inputFile);
}
