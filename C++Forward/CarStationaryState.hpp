#ifndef CAR_STATIONARY_STATE_HPP
#define CAR_STATIONARY_STATE_HPP

#include "CarState.hpp"
#include "CarMovingState.hpp"
#include "Car.hpp"
#include<GL/glut.h>
// Состояние машины, когда она стоит на месте
class CarStationaryState : public CarState {
public:
    // Обрабатывает ввод для неподвижной машины
    void handleInput(Car& car, int key, int action) override;

    // Обновляет состояние неподвижной машины
    void update(Car& car, float deltaTime) override;
};

#endif // CAR_STATIONARY_STATE_HPP
