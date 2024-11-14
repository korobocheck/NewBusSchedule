#include "schedule.h"
#include <iostream>
#include <string>

int main() {
    Schedule schedule;
    int choice;

    do {
        std::cout << "\n1. Добавить рейс\n2. Показать рейсы\n3. Обновить рейс\n4. Удалить рейс\n5. Рассчитать свободные промежутки\n6. Сравнить рейсы\n0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string route, date, departureTime, arrivalTime;
            std::cout << "Введите маршрут: ";
            std::cin >> route;
            std::cout << "Введите дату (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Введите время отправления (HH:MM): ";
            std::cin >> departureTime;
            std::cout << "Введите время прибытия (HH:MM): ";
            std::cin >> arrivalTime;
            schedule.addTrip(route, date, departureTime, arrivalTime);
        } else if (choice == 2) {
            schedule.listTrips();
        } else if (choice == 3) {
            int index;
            std::string newRoute, newDate, newDepartureTime, newArrivalTime;
            std::cout << "Введите индекс рейса для обновления: ";
            std::cin >> index;
            std::cout << "Введите новый маршрут: ";
            std::cin >> newRoute;
            std::cout << "Введите новую дату (YYYY-MM-DD): ";
            std::cin >> newDate;
            std::cout << "Введите новое время отправления (HH:MM): ";
            std::cin >> newDepartureTime;
            std::cout << "Введите новое время прибытия (HH:MM): ";
            std::cin >> newArrivalTime;
            schedule.updateTrip(index, newRoute, newDate, newDepartureTime, newArrivalTime);
        } else if (choice == 4) {
            int index;
            std::cout << "Введите индекс рейса для удаления: ";
            std::cin >> index;
            schedule.deleteTrip(index);
        } else if (choice == 5) {
            schedule.calculateFreeIntervals();
        } else if (choice == 6) {
            int index1, index2;
            std::cout << "Введите индексы двух рейсов для сравнения: ";
            std::cin >> index1 >> index2;
            const auto* trip1 = schedule.getTrip(index1);
            const auto* trip2 = schedule.getTrip(index2);
            if (trip1 && trip2) {
                if (*trip1 == *trip2) {
                    std::cout << "Рейсы идентичны." << std::endl;
                } else if (*trip1 < *trip2) {
                    std::cout << "Первый рейс отправляется раньше второго." << std::endl;
                } else if (*trip1 > *trip2) {
                    std::cout << "Первый рейс отправляется позже второго." << std::endl;
                }
            } else {
                std::cerr << "Неверные индексы!" << std::endl;
            }
        }

    } while (choice != 0);

    return 0;
}