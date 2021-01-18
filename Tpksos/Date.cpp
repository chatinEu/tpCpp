
#include "date.h"
#include <iostream>
#include <cassert>

bool Date::checkDate(int month, int day) const {
	bool status = true;
	if ((month < 1) || (month > 12) || (day > 31 || day <1)){
		status = false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& day > 30 ) {
		status = false;
	}
	else if ((month == 2) && day > 28) {
		status = false;
	}
	
	return status;
}

bool Date::operator>(Date date) const{
	if (getYear() < date.getYear())
		return false;
	else if (getMonth() < date.getMonth())
		return false;
	else if (getDay() < date.getDay())
		return false;
	return true;
}


bool Date::operator<(Date date) const{
	if (getYear() < date.getYear())
		return true;
	else if (getYear() > date.getYear())
		return false;

	// this year== date year
	else if (getMonth() > date.getMonth())
		return false;
	else if (getDay() > date.getDay())
		return false;
	return true;
}

int Date::operator-(Date date) const{
	return (getYear() * 365 + getMonth() * 30 + getDay()) - (date.getYear() * 365 + date.getMonth() * 30 + date.getDay());
}

Date::Date(int month, int day, int year):_day(day),_month(month),_year(year){
	bool status = checkDate(month, day);
}

Date::~Date() {
	//this is a destructor
	//std::cout << "  Destructor: " << _month << "/" << _day << '\n';
}
int Date::getMonth() const{
	return _month;
}

int Date::getDay() const{
	return _day;
}
int Date::getYear() const{
	return _year;
}

Date Date::nextDay() {
	Date next(_month, _day + 1, _year);
	return next;
}
void Date::setYear(int year){
	_year = year;
}
std::string Date::toString() const{
	/*std::string month[12] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
	std::string to_display;
	to_display = month[_month - 1] + "/" + std::to_string(_day);
	return to_display;*/
	return std::to_string(getDay()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getYear());
}

void Date::setMonth(int month) {
	assert((month >= 1) && (month <= 12) && "Month is not valid");
	_month = month;
}

void Date::setDay(int day) {
	assert(checkDate(_month, day) && "Day is not valid");
	_day = day;
}