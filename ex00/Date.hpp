#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <exception>

// Fuck it, Date class.
// :O
class Date {
	private:
		int _year;
		int _month;
		int _day;
	public:
		// Constructors & Destructors.
		Date(void);
		Date(const std::string& dateString);
		Date(const Date& toCopy);
		~Date(void);
		// Operators.
		Date& operator=(const Date& toCopy);
		bool operator==(const Date& date) const;
		bool operator==(const std::string& dateString) const;
		bool operator!=(const Date& date) const;
		bool operator<(const Date& date) const;
		bool operator>(const Date& date) const;
		// Methods.
		void printDate(void) const;
		std::string	dateString(void) const;
};

#endif // DATE_H
