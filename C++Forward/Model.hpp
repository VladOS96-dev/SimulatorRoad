#ifndef MODEL_HPP
#define MODEL_HPP

#include <cmath>
#include <vector>
#include <string>
#include "Road.hpp"
#include "Car.hpp"
#include <chrono>
#include "UpdateHandler.hpp"

#include <map>
#include <algorithm> 

class UpdateHandler; // Forward declaration

class Model {
public:
    Model(); // Конструктор модели

    // Обновление модели
    void update(bool scrollMode, float deltaTime);

    // Получение ссылки на автомобиль
    const Car& getCar() const;

    // Получение сообщений
    const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& getMessages() const;

    // Получение дороги
    const Road& getRoad() const;

    // Получение текущего времени
    const std::chrono::time_point<std::chrono::high_resolution_clock> getCurrentTime();

    // Установка сообщения
    void setMessage(const std::string& key, const std::chrono::time_point<std::chrono::high_resolution_clock>& time);

    // Установка флага пересечения линии
    void setCrossingLine(bool value);

    // Получение значения флага пересечения линии
    bool getCrossingLine() const;

    // Установка времени движения автомобиля
    void setTimeMoveCar(float time);

    // Получение времени движения автомобиля
    float getTimeMoveCar() const;

    // Установка времени начала движения
    void setTimeBeginMove(const std::chrono::time_point<std::chrono::high_resolution_clock>& time);

    // Получение времени начала движения
    const std::chrono::time_point<std::chrono::high_resolution_clock>& getTimeBeginMove() const;

private:
    Road road; // Дорога
    std::shared_ptr<UpdateHandler> updateHandler; // Обработчик обновлений
    Car car; // Модель автомобиля
    std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> messages; // Сообщения модели
    bool crossingLine; // Флаг пересечения линии
    float timeMoveCar; // Время движения автомобиля
    std::chrono::time_point<std::chrono::high_resolution_clock> timeBeginMove; // Время начала движения

    // Инициализация обработчиков
    void initializeHandlers();
};

#endif // MODEL_HPP

