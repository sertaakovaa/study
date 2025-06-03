#include "TicketDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

void TicketDatabase::loadFromFile(const std::string& filename) {
    tickets.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return;
    }

    Ticket t;
    while (file >> t.passengerSurname >> t.trainNumber >> t.departureCity >> t.arrivalCity
        >> t.carriageType >> t.ticketPrice >> t.hasDiscount) {
        tickets.push_back(t);
    }

    std::cout << "Загружено записей: " << tickets.size() << "\n";
}

void TicketDatabase::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка сохранения файла\n";
        return;
    }

    for (const auto& t : tickets) {
        file << t.passengerSurname << " " << t.trainNumber << " "
            << t.departureCity << " " << t.arrivalCity << " "
            << t.carriageType << " " << t.ticketPrice << " "
            << t.hasDiscount << "\n";
    }

    std::cout << "Сохранение завершено\n";
}

void TicketDatabase::showAll() {
    std::cout << "Фамилия\tПоезд\tОткуда\tКуда\tТип\tЦена\tЛьгота\n";
    for (size_t i = 0; i < tickets.size(); ++i) {
        std::cout << i << ") ";
        tickets[i].display();
    }
}

void TicketDatabase::addTicket(const Ticket& ticket) {
    tickets.push_back(ticket);
    std::cout << "Запись добавлена\n";
}

void TicketDatabase::deleteTicket(int index) {
    if (index >= 0 && index < tickets.size()) {
        tickets.erase(tickets.begin() + index);
        std::cout << "Запись удалена\n";
    }
    else {
        std::cout << "Неверный индекс\n";
    }
}

void TicketDatabase::sortByTrainNumber() {
    std::sort(tickets.begin(), tickets.end(), [](const Ticket& a, const Ticket& b) {
        return a.trainNumber < b.trainNumber;
        });
    std::cout << "Сортировка завершена\n";
}

void TicketDatabase::searchByTrainNumber(unsigned short trainNumber) {
    for (const auto& t : tickets) {
        if (t.trainNumber == trainNumber) {
            t.display();
        }
    }
}

void TicketDatabase::filterByPriceRange(float min, float max) {
    for (const auto& t : tickets) {
        if (t.ticketPrice >= min && t.ticketPrice <= max) {
            t.display();
        }
    }
}

void TicketDatabase::popularCities() {
    std::map<std::string, int> count;
    for (const auto& t : tickets) {
        count[t.departureCity]++;
        count[t.arrivalCity]++;
    }

    std::vector<std::pair<std::string, int>> sorted(count.begin(), count.end());
    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
        });

    for (const auto& [city, c] : sorted) {
        std::cout << city << ": " << c << " билетов\n";
    }
}

void TicketDatabase::moveToExtraServiceBase(char type) {
    std::vector<Ticket> extra, remaining;

    for (const auto& t : tickets) {
        if (t.carriageType == type && !t.hasDiscount) {
            extra.push_back(t);
        }
        else {
            remaining.push_back(t);
        }
    }

    std::ofstream out("extra_service.txt");
    for (const auto& t : extra) {
        out << t.passengerSurname << " " << t.trainNumber << " "
            << t.departureCity << " " << t.arrivalCity << " "
            << t.carriageType << " " << t.ticketPrice << " "
            << t.hasDiscount << "\n";
    }

    tickets = remaining;
    std::cout << "Перенесено: " << extra.size() << " записей в extra_service.txt\n";
}