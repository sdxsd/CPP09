#include "BitcoinExchange.hpp"

int main(void) {
	std::ifstream x;
	x.open("data.csv");
	BitcoinExchange exchange(x);
}
