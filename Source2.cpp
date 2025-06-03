#include "Ticket.h"

void Ticket::display() const {
    std::cout << passengerSurname << "\t" << trainNumber << "\t"
        << departureCity << "\t" << arrivalCity << "\t"
        << carriageType << "\t" << ticketPrice << "\t"
        << (hasDiscount ? "Yes" : "No") << std::endl;
}