#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <string>
#include "math.h"


class Date{
private:
     int year;
     int month;
     int day;
public:
     Date(int _year = 1970, int _month = 01, int _day = 01);
     Date(const Date& date_old);
     int getYear() const;
     int getMonth() const;
     int getDay() const;
	 int date_to_days() const;

     friend int operator- (const Date& firstDate,const Date&  secondDate);
     void operator+= (int numberOfDays);
     void operator-= (int numberOfDays);
     friend bool operator== (const Date& firstDate, const Date& secondDate){return firstDate.date_to_days()==secondDate.date_to_days();};
     friend bool operator!= (const Date& firstDate, const Date&  secondDate){return firstDate.date_to_days()!=secondDate.date_to_days();};
     Date& operator= (const Date& _oldDate);
     friend std::ostream& operator<< (std::ostream& stream, const Date& date);



};


inline Date operator+(Date date,int numberOfDays);

inline Date operator-(Date date,int numberOfDays);

inline Date operator- (int numberOfDays, Date date);

inline Date operator+ (int numberOfDays,Date date);






void get_days_in_months_array(short * days_in_months);



Date days_to_date(int days);


#endif

