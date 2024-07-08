#include "CarStationaryState.hpp"

// ������������ ���� ��� ����������� ������
void CarStationaryState::handleInput(Car& car, int key, int action) {
    if (action == GLUT_DOWN) {
        switch (key) {
        case GLUT_KEY_UP:
            car.setState(new CarMovingState()); // ����������� ��������� �� ����������
            car.increaseSpeed(); // ����������� �������� ������
            break;
        }
    }
}

// ��������� ��������� ����������� ������
void CarStationaryState::update(Car& car, float deltaTime) {
    // ��� ������������� ��������� ���������, ���� ������ ����� �� �����
}