
#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date {
public:
	bool operator> (Date date) const;
	bool operator< (Date date) const;
	int operator- (Date date) const;
	Date(int month, int day, int year);
	Date() = default;
	~Date();
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	bool checkDate(int month, int day) const;
	Date nextDay();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	std::string toString() const;
private:
	bool isBefore(Date d) const;
	int _month;
	int _day;
	int _year;
};
#endif // DATE_H