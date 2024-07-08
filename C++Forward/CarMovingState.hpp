#ifndef CAR_MOVING_STATE_HPP
#define CAR_MOVING_STATE_HPP

#include "CarState.hpp"
#include "Car.hpp"
#include<GL/glut.h>
// Состояние машины, когда она движется
class CarMovingState : public CarState {
public:
    // Обрабатывает ввод для движущейся машины
    void handleInput(Car& car, int key, int action) override;

    // Обновляет состояние движущейся машины
    void update(Car& car, float deltaTime) override;
};

#endif // CAR_MOVING_STATE_HPP
