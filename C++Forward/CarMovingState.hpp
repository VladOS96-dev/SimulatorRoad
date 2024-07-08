#ifndef CAR_MOVING_STATE_HPP
#define CAR_MOVING_STATE_HPP

#include "CarState.hpp"
#include "Car.hpp"
#include<GL/glut.h>
// ��������� ������, ����� ��� ��������
class CarMovingState : public CarState {
public:
    // ������������ ���� ��� ���������� ������
    void handleInput(Car& car, int key, int action) override;

    // ��������� ��������� ���������� ������
    void update(Car& car, float deltaTime) override;
};

#endif // CAR_MOVING_STATE_HPP
