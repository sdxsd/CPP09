#include "BitcoinExchange.hpp"
#include <stdexcept>

BitcoinExchange::BitcoinExchange(std::ifstream& database) {
	std::string	entry;

	if (!database.is_open())
		throw std::invalid_argument("Invalid file stream");
	while (std::getline(database, entry)) {
		_db[entry.substr(0, entry.find(','))] = std::stof(entry.substr(entry.find(','), entry.length()));
	}
	for (const auto& [key, value] : _db)
		std::cout << key << value;
}
