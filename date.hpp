#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <string>


class Date{
    private:
     int year;
     int month;
     int day;
     void checkdate();
    public:
     short days_in_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     Date(int _year = 1970, int _month = 01, int _day = 01);
     int getYear();
     int getMonth();
     int getDay();
     Date& operator+ (int numberOfDays) const;
     friend Date& operator+ (int numberOfDays, const Date& _date);
     Date& operator- (int numberOfDays);
     Date& operator+= (int numberOfDays);
     Date& operator-= (int numberOfDays);
     friend int operator- (const Date& firstDate,const Date&  secondDate);
     bool operator== (const Date&  secondDate);
     bool operator!= (const Date&  secondDate);
     Date& operator= (const Date& _oldDate);
     friend operator<< (std::ostream& stream, const Date& _date);



};

class GermanDateFormat{
	public:
		string format(const Date& date);


};

class NormalDateFormat{
	public:
		string format(const Date& date);
};


#endif

