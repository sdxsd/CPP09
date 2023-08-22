#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& database) {
	std::string	entry;

	if (!database.is_open())
		throw std::invalid_argument("Invalid file stream");
	std::getline(database, entry);
	while (std::getline(database, entry))
		_db[entry.substr(0, entry.find(','))] = std::stof(entry.substr(entry.find(',') + 1, entry.length()));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) {
	_db = toCopy._db;
}

BitcoinExchange::~BitcoinExchange(void) {
	;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy) {
	if (this != &toCopy)
		this->_db = toCopy._db;
	return (*this);
}

void BitcoinExchange::parseInput(std::ifstream& input) {
	std::string	entry;
	std::string date;
	std::string value;

	if (!input.is_open())
		throw std::invalid_argument("Invalid file stream");
	std::getline(input, entry);
	while (std::getline(input, entry)) {
		date = entry.substr(0, entry.find(" |"));
		value = entry.substr(entry.find("|") + 1, entry.length());
		auto iter = _db.find(Date(date));
		if (iter != _db.end()) {
			std::cout << iter->first.dateString() << " => " << value << " = " << std::stof(value) * iter->second;
		}
	}
}
