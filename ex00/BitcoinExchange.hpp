#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <map>
#include <fstream>
#include <string>
#include <exception>
#include <iostream>

// Sidenote: I don't like the _variable standard for private variables.
// Seems annoying...

class BitcoinExchange {
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinExchange(std::ifstream& database);
		// BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange(void);
		// BitcoinExchange& operator=(const BitcoinExchange& toCopy);
		// void parseInput(std::ifstream input);
};

#endif // BITCOINEXCHANGE_H
