#include "CarMovingState.hpp"

// ������������ ���� ��� ���������� ������
void CarMovingState::handleInput(Car& car, int key, int action) {
    if (action == GLUT_DOWN) {
        switch (key) {
        case GLUT_KEY_LEFT:
            car.rotateLeft();  // ������������ ������ �����
            car.startTurn();   // �������� �������
            break;
        case GLUT_KEY_RIGHT:
            car.rotateRight(); // ������������ ������ ������
            car.startTurn();   // �������� �������
            break;
        case GLUT_KEY_UP:
            car.increaseSpeed(); // ����������� �������� ������
            break;
        case GLUT_KEY_DOWN:
            car.decreaseSpeed(); // ��������� �������� ������
            break;
        }
    }
    else if (action == GLUT_UP) {
        switch (key) {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT:
            car.stopTurn(); // ������������� �������
            break;
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
            car.setSpeed(0.0f); // ������������� �������� �� 0
            break;
        }
    }
}

// ��������� ��������� ���������� ������
void CarMovingState::update(Car& car, float deltaTime) {
    car.update(deltaTime); // ��������� ��������� ������
}