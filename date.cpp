#include "date.hpp"
#include "iomanip"
#include <iostream>

void get_days_in_months_array(short * days_in_months)
{
    int i;
    short days_array[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<12;i++)
        days_in_months[i]=days_array[i];

}


Date::Date(int _year, int _month, int _day)
{
	year=_year;
	month=_month;
	day=_day;
}

Date::Date(const Date& date_old) {
    this->year = date_old.getYear();
    this->month = date_old.getMonth();
    this -> day = date_old.getDay();
}



int Date::getYear() const
    {
        return year;
    }
int Date::getMonth() const
    {
        return month;
    }
int Date::getDay() const
    {
        return day;
    }



int operator- (const Date& firstDate,const Date&  secondDate){ return date_to_days(firstDate)-date_to_days(secondDate); }

Date& Date::operator= (const Date& new_date){

    day = new_date.getDay();
    month = new_date.getMonth();
    year = new_date.getYear();
    return *this;
}


void Date::operator+= (int numberOfDays){
    Date result = days_to_date(date_to_days(*this)+numberOfDays);
    this->day=result.getDay();
    this->month=result.getMonth();
    this->year=result.getYear();
}

void Date::operator-= (int numberOfDays){
    Date result = days_to_date(date_to_days(*this)-numberOfDays);
    this->day=result.getDay();
    this->month=result.getMonth();
    this->year=result.getYear();
}



bool operator== (const Date& firstDate, const Date& secondDate){
return date_to_days(firstDate)==date_to_days(secondDate);
}
bool operator!= (const Date& firstDate, const Date&  secondDate){
    return date_to_days(firstDate)!=date_to_days(secondDate);
}


std::ostream& operator<< (std::ostream& stream, const Date& date)
{
    stream <<  std::setfill('0') <<std::setw(4)<< date.getYear() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getMonth() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getDay();
    if(date.getYear()<1970)
        stream << " Date is from time before the epoch";

    return stream;
}

int date_to_days(const Date& date)
{
    int i=0;
    short days_in_months[12];
    get_days_in_months_array(days_in_months);
    int result = date.getYear()*365;
    for(i=1;i<date.getMonth();i++)
    {
        result+=days_in_months[i-1];
    }
    result+=date.getDay();
    return result;

}


Date days_to_date(int days)
{
    int i,new_years;
    int new_months=1;
    int new_days=0;

    short days_in_months[12];
    get_days_in_months_array(days_in_months);
    if(days%365!=0)
        new_years=days/365;
    else
        new_years=days/365-1;


    days -= new_years*365;
    for(i=0;i<12;i++)
    {
        if(days>days_in_months[i]) {
            new_months++;
            days -= days_in_months[i];
        }
        else
            break;
    }
    new_days+=days;
    if(new_days == 0)
        new_days =1;

    Date result = Date(new_years,new_months,new_days);
    return result;
}