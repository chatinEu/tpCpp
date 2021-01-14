
#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date {
public:
	bool operator> (Date date);
	bool operator< (Date date);
	int operator- (Date date);
	Date(int month, int day, int year);
	Date() = default;
	~Date();
	int getMonth() const;
	int getDay() const;
	int getYear();
	bool checkDate(int month, int day) const;
	Date nextDay();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	std::string toString();
private:
	int _month;
	int _day;
	int _year;
};
#endif // DATE_H