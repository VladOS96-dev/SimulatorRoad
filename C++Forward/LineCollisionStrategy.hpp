#ifndef LINE_COLLISION_STRATEGY_HPP
#define LINE_COLLISION_STRATEGY_HPP

#include "CollisionStrategy.hpp"
#include "Line.hpp"
#include "Car.hpp"

// Класс LineCollisionStrategy, реализующий стратегию проверки столкновения с линией
class LineCollisionStrategy : public CollisionStrategy {
private:
    const Line& line;  // Ссылка на объект линии
public:
    // Конструктор класса LineCollisionStrategy
    LineCollisionStrategy(const Line& l) : line(l) {}

    // Переопределение виртуальной функции для проверки столкновения с автомобилем
    bool checkCollision(const Car& car) const override;
};

#endif // LINE_COLLISION_STRATEGY_HPP
