#pragma once
#include <string>
#include <iostream>

class Ticket {
public:
    std::string passengerSurname;
    unsigned short int trainNumber;
    std::string departureCity;
    std::string arrivalCity;
    char carriageType;
    float ticketPrice;
    bool hasDiscount;

    void display() const;
};