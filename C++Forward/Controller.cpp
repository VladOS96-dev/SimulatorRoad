
#include "Controller.hpp"
#include "MoveForwardCommand.hpp"
#include "RotateLeftCommand.hpp"
#include "RotateRightCommand.hpp"
#include"BrakingCommand.hpp"
#include"StopRotateCommand.hpp"
#include "MovementInertiaCommand.hpp"
// ����������� ������ Controller
Controller::Controller(Model* m, View* v) : model(m), view(v), scrollMode(false) {
    lastFrameTime = std::chrono::high_resolution_clock::now();
    Car& car = const_cast<Car&>(model->getCar());

    // ������������� ������� ��� ������
    setCommand(GLUT_KEY_UP, new MoveForwardCommand(&car));
    setCommand(GLUT_KEY_LEFT, new RotateLeftCommand(&car));
    setCommand(GLUT_KEY_RIGHT, new RotateRightCommand(&car));
    setCommand(GLUT_KEY_DOWN, new BrakingCommand(&car));

    // ������������� ������� ��� ���������� ������
    setReleaseCommand(GLUT_KEY_LEFT, new StopRotateCommand(&car));
    setReleaseCommand(GLUT_KEY_RIGHT, new StopRotateCommand(&car));
    setReleaseCommand(GLUT_KEY_UP, new BrakingCommand(&car));

}

// ������������ ������� ������
void Controller::onKeyEvent(int key, int action) {
    if (action == GLUT_DOWN) {
        if (keyBindings.find(key) != keyBindings.end()) {
            keyBindings[key]->execute();  // ��������� �������, ��������� � ��������
        }
    }
    else if (action == GLUT_UP) {
        if (keyReleaseBindings.find(key) != keyReleaseBindings.end()) {
            keyReleaseBindings[key]->execute();  // ��������� �������, ��������� � ���������� ��������
        }
    }
}

// ��������� ��������� ������
void Controller::update() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    model->update(scrollMode, deltaTime.count());  // ��������� ������

    view->render(model->getCar(), model->getRoad(), model->getMessages());  // �������� ���
}

// ������������� ������� ��� ������
void Controller::setCommand(int key, Command* command) {
    keyBindings[key] = command;
}
// ������������� ������� ��� ���������� ������
void Controller::setReleaseCommand(int key, Command* command) {
    keyReleaseBindings[key] = command;
}