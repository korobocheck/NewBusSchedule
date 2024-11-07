#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

// Класс Schedule для управления автобусными рейсами
class Schedule {
private:
    // Структура для хранения данных о рейсе
    struct BusTrip {
        std::string route;
        std::string date; // Формат: YYYY-MM-DD
        std::string departureTime; // Формат: HH:MM
        std::string arrivalTime; // Формат: HH:MM
    };

    // Вектор указателей на автобусные рейсы
    std::vector<BusTrip*> trips;

public:
    // Создать рейс
    void addTrip(const std::string& route, const std::string& date, const std::string& departureTime, const std::string& arrivalTime);

    // Показать все рейсы
    void listTrips() const;

    // Обновить рейс
    void updateTrip(int index, const std::string& newRoute, const std::string& newDate, const std::string& newDepartureTime, const std::string& newArrivalTime);

    // Удалить рейс
    void deleteTrip(int index);

    // Рассчитать свободные промежутки времени между рейсами
    void calculateFreeIntervals() const;

    // Деструктор
    ~Schedule();
};

#endif // SCHEDULE_H