#include "date.hpp"

Date::Date(int _year, int _month, int _day)
{
	year=_year;
	month=_month;
	day=_day;
}

void Date::checkdate()
{
	while(day>days_in_months[month-1])
	{
		day -= days_in_months[month - 1];
		month++;
	}
	while(month>12)
	{
		month -= 12;
		year++;
	}
}


int Date::getYear()
    {
        return year;
    }
int Date::getMonth()
    {
        return month;
    }
int Date::getDay()
    {
        return day;
    }

Date& Date::operator+(int numberOfDays) const
{
	day=day+numberOfDays;
	checkdate();
	return this;
}
