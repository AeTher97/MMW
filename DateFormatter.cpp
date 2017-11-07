//
// Created by Michał on 07.11.2017.
//

#include "DateFormatter.h"
#include "iomanip"


std::string GermanDateFormatter::format(const Date& date) const
{
    std::ostringstream stream;
    stream <<  std::setfill('0') <<std::setw(4)<< date.getYear() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getMonth() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getDay();
    return stream.str();
}

std::string ComputerDateFormatter::format(const Date& date) const
{
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << date.getDay() << '-';
    stream << std::setfill('0') << std::setw(2) << date.getMonth() << '-';
    stream <<  std::setfill('0') <<std::setw(4)<< date.getYear();

    return stream.str();
}