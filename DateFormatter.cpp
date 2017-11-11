//
// Created by Michał on 07.11.2017.
//

#include <sstream>
#include "DateFormatter.h"

#include "iomanip"


std::string ComputerDateFormatter::format(const Date& date) const
{
    std::ostringstream stream;
    stream <<  std::setfill('0') <<std::setw(4)<< date.getYear() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getMonth() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getDay();
    if(date.getYear()<1970)
        stream << " Date is from time before the computer era";
    return stream.str();
}

std::string GermanDateFormatter::format(const Date& date) const
{
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << date.getDay() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getMonth() << '-';
    stream <<  std::setfill('0') <<std::setw(4)<< date.getYear();
    if(date.getYear()<1970)
        stream << " Date is from time before the epoch";

    return stream.str();
}