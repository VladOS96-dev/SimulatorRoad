#include "CarStationaryState.hpp"

// Обрабатывает ввод для неподвижной машины
void CarStationaryState::handleInput(Car& car, int key, int action) {
    if (action == GLUT_DOWN) {
        switch (key) {
        case GLUT_KEY_UP:
            car.setState(new CarMovingState()); // Переключает состояние на движущееся
            car.increaseSpeed(); // Увеличивает скорость машины
            break;
        }
    }
}

// Обновляет состояние неподвижной машины
void CarStationaryState::update(Car& car, float deltaTime) {
    // Нет необходимости обновлять состояние, если машина стоит на месте
}