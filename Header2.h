#pragma once
#include <vector>
#include <string>
#include "Ticket.h"

class TicketDatabase {
private:
    std::vector<Ticket> tickets;

public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void showAll();
    void addTicket(const Ticket& ticket);
    void deleteTicket(int index);
    void sortByTrainNumber();
    void searchByTrainNumber(unsigned short trainNumber);
    void filterByPriceRange(float min, float max);
    void popularCities();
    void moveToExtraServiceBase(char carriageType);
};