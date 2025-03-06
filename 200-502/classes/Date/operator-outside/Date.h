#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
	int year;
	int month;
	int day;

	bool isLeapYear(int year);
	bool validDay(int day);
	bool validMonth(int month);
	bool validYear(int year);

public:
	Date();
	Date(int year, int month, int day);
		std::string to_string();
		int getDay() const;
		void setDay(int day);
		int getMonth() const;
		void setMonth(int month);
		int getYear() const;
		void setYear(int year);
		// add == declaration
		bool operator==(const Date&) const;
		// add < declaration
		bool operator<(const Date&) const;
		// lhs < rhs
		// lhs: left hand side
		// rhs: right hand side
};

std::ostream& operator<<(std::ostream& os, const Date& d);

#endif