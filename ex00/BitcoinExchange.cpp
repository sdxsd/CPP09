#include "BitcoinExchange.hpp"

bool BitcoinExchange::_checkInput(const std::string& entry) const {
	Date date = Date(entry.substr(0, entry.find(" |")));
	long value = std::stol(entry.substr(entry.find("|") + 1, entry.length()));
	if (!date.getYear() || !date.getMonth() || !date.getDay()) {
		std::cerr << "Error: bad input => " << entry.substr(0, entry.find(" |")) << std::endl;
		return (false);
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (value > std::numeric_limits<int>::max()) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

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

// Trust me it makes sense.
void BitcoinExchange::parseInput(std::ifstream& input) {
	std::string	entry;
	Date		date;
	float		value;

	if (!input.is_open())
		throw std::invalid_argument("Invalid file stream");
	std::getline(input, entry);
	while (std::getline(input, entry)) {
		if (_checkInput(entry)) {
			date = Date(entry.substr(0, entry.find(" |")));
			value = std::stof(entry.substr(entry.find("|") + 1, entry.length()));
			auto iter = _db.find(date);
			if (iter != _db.end()) {
				std::cout << iter->first.dateString() << " => " << value << " = "
						  << value * iter->second << std::endl;
			}
			else {
				iter = _db.find(--date);
				while (iter == _db.end() && date != Date("1-1-1"))
					iter = _db.find(--date);
				if (date == Date("1-1-1"))
					std::cout << "Unable to find entry in database." << std::endl;
				else
					std::cout << iter->first.dateString() << " => " << value << " = "
							  << value * iter->second << std::endl;

			}
		}
	}
}
