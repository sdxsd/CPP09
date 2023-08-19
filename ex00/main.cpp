#include "BitcoinExchange.hpp"

int main(void) {
	std::ifstream x("data.csv");
	BitcoinExchange exchange(x);
}
