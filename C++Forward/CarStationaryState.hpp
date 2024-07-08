#ifndef CAR_STATIONARY_STATE_HPP
#define CAR_STATIONARY_STATE_HPP

#include "CarState.hpp"
#include "CarMovingState.hpp"
#include "Car.hpp"
#include<GL/glut.h>
// ��������� ������, ����� ��� ����� �� �����
class CarStationaryState : public CarState {
public:
    // ������������ ���� ��� ����������� ������
    void handleInput(Car& car, int key, int action) override;

    // ��������� ��������� ����������� ������
    void update(Car& car, float deltaTime) override;
};

#endif // CAR_STATIONARY_STATE_HPP
