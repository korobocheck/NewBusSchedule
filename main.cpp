#include "schedule.h"
#include <iostream>
#include "windows.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Schedule schedule;
    int choice;

    do {
        std::cout << "\n1. Добавить рейс\n2. Показать рейсы\n3. Обновить рейс\n4. Удалить рейс\n5. Рассчитать свободные промежутки\n0. Выход\n";
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
        }

    } while (choice != 0);

    return 0;
}