#include <iostream>
#include "TicketDatabase.h"

int main() {
    TicketDatabase db;
    int choice;

    do {
        std::cout << "\n--- Железнодорожная касса ---\n";
        std::cout << "1. Загрузить БД из файла\n";
        std::cout << "2. Показать все записи\n";
        std::cout << "3. Добавить запись\n";
        std::cout << "4. Удалить запись\n";
        std::cout << "5. Сохранить БД в файл\n";
        std::cout << "6. Сортировать по номеру поезда\n";
        std::cout << "7. Поиск по номеру поезда\n";
        std::cout << "8. Выборка по диапазону цен\n";
        std::cout << "9. Популярные города\n";
        std::cout << "10. Перенести записи с доп. услугами\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            db.loadFromFile("tickets.txt");
            break;
        }
        case 2: {
            db.showAll();
            break;
        }
        case 3: {
            Ticket t;
            std::cout << "Фамилия: "; std::cin >> t.passengerSurname;
            std::cout << "Номер поезда: "; std::cin >> t.trainNumber;
            std::cout << "Город отправления: "; std::cin >> t.departureCity;
            std::cout << "Город прибытия: "; std::cin >> t.arrivalCity;
            std::cout << "Тип вагона (буква): "; std::cin >> t.carriageType;
            std::cout << "Цена билета: "; std::cin >> t.ticketPrice;
            std::cout << "Есть льгота (1 - да, 0 - нет): "; std::cin >> t.hasDiscount;
            db.addTicket(t);
            break;
        }
        case 4: {
            int index;
            std::cout << "Введите номер записи для удаления: ";
            std::cin >> index;
            db.deleteTicket(index);
            break;
        }
        case 5: {
            db.saveToFile("tickets.txt");
            break;
        }
        case 6: {
            db.sortByTrainNumber();
            break;
        }
        case 7: {
            unsigned short number;
            std::cout << "Введите номер поезда: ";
            std::cin >> number;
            db.searchByTrainNumber(number);
            break;
        }
        case 8: {
            float min, max;
            std::cout << "Введите диапазон цен (min max): ";
            std::cin >> min >> max;
            db.filterByPriceRange(min, max);
            break;
        }
        case 9: {
            db.popularCities();
            break;
        }
        case 10: {
            char type;
            std::cout << "Введите тип вагона (буква): ";
            std::cin >> type;
            db.moveToExtraServiceBase(type);
            break;
        }
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор\n";
        }

    } while (choice != 0);

    return 0;
}