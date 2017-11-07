//
// Created by Michał on 07.11.2017.
//
#include <iostream>
#include "Date.hpp"
#ifndef INFORMATYKA_DATEFORMATTER_H
#define INFORMATYKA_DATEFORMATTER_H


class DateFormatter{
public:
    virtual std::string format(const Date& d) const = 0;
};

class GermanDateFormatter: public DateFormatter{
public:
    std::string format(const Date& date) const;
};


class ComputerDateFormatter{
public:
    std::string format(const Date& date) const;
};


#endif //INFORMATYKA_DATEFORMATTER_H
