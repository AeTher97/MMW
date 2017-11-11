#include <iostream>
#include "date.hpp"
#include "DateFormatter.h"


int main() {
    Date date = Date();
    Date date2 = Date();   //tworzenie obiektow domyslnie ustawiony 1970-01-01
    Date date3 = Date();
    ComputerDateFormatter computer_formatter = ComputerDateFormatter();
    GermanDateFormatter german_formatter = GermanDateFormatter();

    for (int i = 0; i < 365; i++) {
        date -= 1;
        std::cout << computer_formatter.format(date) << std::endl;   //odejmownaie od daty dzialanie formatera

    }
    date2-=365;
    date3 = date2;
    if(date==date3)
    std::cout << " true"<<std::endl;
    if(date!=date3)
        std::cout << " false"<<std::endl;
    date+=1;                                             //operatory logiczne
    if(date==date3)
        std::cout << " true"<<std::endl;
    if(date!=date3)
        std::cout << " false"<<std::endl;

    date = date2+100;


    std::cout << computer_formatter.format(date) << std::endl;
    date = 1580000-date2;
    std::cout << computer_formatter.format(date) << std::endl;
    date += 20;
    std::cout << computer_formatter.format(date) << std::endl;             //dodawananie odejmowanie z obu stron zanku przypisywanie
    date = -140000 + date;
    std::cout << computer_formatter.format(date) << std::endl;
    std::cout << date2-date << std::endl;

    Date date4 = Date(date);
    std::cout << german_formatter.format(date4) << std::endl; //konstruktor kopiujacy

    std::cout << date; //przeciazony operator wyjscia


    return 0;
}