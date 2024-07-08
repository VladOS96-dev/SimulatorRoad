#include "LineCollisionStrategy.hpp"

bool LineCollisionStrategy::checkCollision(const Car& car) const {
    // Проверяем, находится ли автомобиль в пределах линии с учетом её ширины
    return car.getX() >= line.getStartX() - line.getWidth() &&
        car.getX() <= line.getEndX() + line.getWidth() &&
        car.getY() >= line.getStartY() &&
        car.getY() <= line.getEndY();
}
