#ifndef COLLISION_STRATEGY_HPP
#define COLLISION_STRATEGY_HPP

#include "Car.hpp"
class Car;
// Абстрактный класс CollisionStrategy для стратегий проверки столкновений
class CollisionStrategy {
public:
    // Виртуальная функция для проверки столкновения с автомобилем
    virtual bool checkCollision(const Car& car) const = 0;

    // Виртуальный деструктор для правильного управления памятью
    virtual ~CollisionStrategy() = default;
};

#endif // COLLISION_STRATEGY_HPP
