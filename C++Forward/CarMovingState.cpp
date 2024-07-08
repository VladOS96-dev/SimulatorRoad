#include "CarMovingState.hpp"

// Обрабатывает ввод для движущейся машины
void CarMovingState::handleInput(Car& car, int key, int action) {
    if (action == GLUT_DOWN) {
        switch (key) {
        case GLUT_KEY_LEFT:
            car.rotateLeft();  // Поворачивает машину влево
            car.startTurn();   // Начинает поворот
            break;
        case GLUT_KEY_RIGHT:
            car.rotateRight(); // Поворачивает машину вправо
            car.startTurn();   // Начинает поворот
            break;
        case GLUT_KEY_UP:
            car.increaseSpeed(); // Увеличивает скорость машины
            break;
        case GLUT_KEY_DOWN:
            car.decreaseSpeed(); // Уменьшает скорость машины
            break;
        }
    }
    else if (action == GLUT_UP) {
        switch (key) {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT:
            car.stopTurn(); // Останавливает поворот
            break;
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
            car.setSpeed(0.0f); // Устанавливает скорость на 0
            break;
        }
    }
}

// Обновляет состояние движущейся машины
void CarMovingState::update(Car& car, float deltaTime) {
    car.update(deltaTime); // Обновляет параметры машины
}