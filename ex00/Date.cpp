#include "Date.hpp"
#include <stdexcept>
#include <iostream>

// Constructors & Destructors.

Date::Date(void) {
	_year = _month = _day = 0;
}

Date::Date(const std::string& dateString) {
	std::istringstream	stringStream(dateString);
	std::string			splitStrings[3];

	for (int i = 0; i < 3; i++) {
		if (!std::getline(stringStream, splitStrings[i], '-')) {
			_year = 0;
			return ;
		}
	}
	_year = std::stoi(splitStrings[0]);
	if (_year < 0)
		_year = 0;
	_month = std::stoi(splitStrings[1]);
	if (_month < 1 || _month > 12)
		_month = 0;
	_day = std::stoi(splitStrings[2]);
	if (_day > daysPerMonth[_month - 1])
		_day = 0;
}

Date::Date(const Date& toCopy) {
	_year = toCopy._year;
	_month = toCopy._month;
	_day = toCopy._day;
}

Date::~Date(void) {
	;
}

// Operators.

Date& Date::operator=(const Date& toCopy) {
	if (this != &toCopy) {
		this->_year = toCopy._year;
		this->_month = toCopy._month;
		this->_day = toCopy._day;
	}
	return (*this);
}

bool Date::operator==(const Date& date) const {
	if (this == &date)
		return (true);
	else if (this->_year == date._year && this->_month == date._month && this->_day == date._day)
		return (true);
	return (false);
}

bool Date::operator==(const std::string& date) const {
	Date convertedString(date);

	if (convertedString == *this)
		return (true);
	return (false);
}

bool Date::operator!=(const Date& date) const {
	if (this == &date)
		return (false);
	else if (this->_year == date._year && this->_month == date._month && this->_day == date._day)
		return (false);
	return (true);
}

bool Date::operator<(const Date& date) const {
	if (this->_year < date._year)
		return (true);
	if (this->_year == date._year)
		;
	else
		return (false);
	if (this->_month < date._month)
		return (true);
	else if (this->_month == date._month)
		;
	else
		return (false);
	if (this->_day < date._day)
		return (true);
	else if (this->_day == date._day)
		return (false);
	else
		return (false);
}

bool Date::operator>(const Date& date) const {
	if (this->_year > date._year)
		return (true);
	if (this->_year == date._year)
		;
	else
		return (false);
	if (this->_month > date._month)
		return (true);
	else if (this->_month == date._month)
		;
	else
		return (false);
	if (this->_day > date._day)
		return (true);
	else if (this->_day == date._day)
		return (false);
	else
		return (false);
}

// Prefix
Date& Date::operator++(void) {
	++(this->_day);
	if (this->_day > daysPerMonth[_month - 1]) {
		this->_day = 1;
		++(this->_month);
		if (this->_month > 12) {
			this->_month = 1;
			this->_year++;
			if (this->_year > 9999)
				this->_year = 0;
		}
	}
	return (*this);
}

Date Date::operator++(int) {
	Date result(*this);
	++(*this);
	return (result);
}

Date& Date::operator--(void) {
	--(this->_day);
	if (this->_day < 1) {
		this->_month--;
		if (this->_month < 1) {
			this->_month = 12;
			this->_year--;
			if (this->_year < 0)
				this->_year = 9999;
		}
		this->_day = daysPerMonth[_month - 1];
	}
	return (*this);
}

Date Date::operator--(int) {
	Date result(*this);
	--(*this);
	return (result);
}

int Date::getYear(void) const {
	return (_year);
}

int Date::getMonth(void) const {
	return (_month);
}

int Date::getDay(void) const {
	return (_day);
}

void Date::printDate(void) const {
	std::cout << _year << '-' << _month << '-' << _day << std::endl;
}

std::string Date::dateString(void) const {
	return (std::to_string(_year) + "-" + std::to_string(_month) + "-" + std::to_string(_day));
}
