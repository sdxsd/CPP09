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

// Sphaghetti Code :(
void BitcoinExchange::parseInput(std::ifstream& input) {
	std::string	entry;
	Date		date;
	float		value;
	Date		oldDate;

	if (!input.is_open())
		throw std::invalid_argument("Invalid file stream");
	std::getline(input, entry);
	while (std::getline(input, entry)) {
		date = Date(entry.substr(0, entry.find(" |")));
		value = std::stof(entry.substr(entry.find("|") + 1, entry.length()));
		auto iter = _db.find(Date(date));
		if (iter != _db.end()) {
			std::cout << iter->first.dateString() << " =>" << value << " = "
					  << value * iter->second << std::endl;
		}
		else {
			auto dbIter = _db.find(--date);
			while (dbIter == _db.end() && date != Date("1-1-1"))
				auto dbIter = _db.find(--date);
			if (date == Date("1-1-1"))
				std::cout << "Unable to find entry in database." << std::endl;
			else
				std::cout << dbIter->first.dateString() << " =>" << value << " = "
						  << value * dbIter->second << std::endl;
		}
	}
}
