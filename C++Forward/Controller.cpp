
#include "Controller.hpp"
#include "MoveForwardCommand.hpp"
#include "RotateLeftCommand.hpp"
#include "RotateRightCommand.hpp"
#include"BrakingCommand.hpp"
#include"StopRotateCommand.hpp"
#include "MovementInertiaCommand.hpp"
// Конструктор класса Controller
Controller::Controller(Model* m, View* v) : model(m), view(v), scrollMode(false) {
    lastFrameTime = std::chrono::high_resolution_clock::now();
    Car& car = const_cast<Car&>(model->getCar());

    // Устанавливаем команды для клавиш
    setCommand(GLUT_KEY_UP, new MoveForwardCommand(&car));
    setCommand(GLUT_KEY_LEFT, new RotateLeftCommand(&car));
    setCommand(GLUT_KEY_RIGHT, new RotateRightCommand(&car));
    setCommand(GLUT_KEY_DOWN, new BrakingCommand(&car));

    // Устанавливаем команды для отпускания клавиш
    setReleaseCommand(GLUT_KEY_LEFT, new StopRotateCommand(&car));
    setReleaseCommand(GLUT_KEY_RIGHT, new StopRotateCommand(&car));
    setReleaseCommand(GLUT_KEY_UP, new BrakingCommand(&car));

}

// Обрабатывает события клавиш
void Controller::onKeyEvent(int key, int action) {
    if (action == GLUT_DOWN) {
        if (keyBindings.find(key) != keyBindings.end()) {
            keyBindings[key]->execute();  // Выполняет команду, связанную с клавишей
        }
    }
    else if (action == GLUT_UP) {
        if (keyReleaseBindings.find(key) != keyReleaseBindings.end()) {
            keyReleaseBindings[key]->execute();  // Выполняет команду, связанную с отпущенной клавишей
        }
    }
}

// Обновляет состояние машины
void Controller::update() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    model->update(scrollMode, deltaTime.count());  // Обновляет модель

    view->render(model->getCar(), model->getRoad(), model->getMessages());  // Рендерит вид
}

// Устанавливает команды для клавиш
void Controller::setCommand(int key, Command* command) {
    keyBindings[key] = command;
}
// Устанавливает команды для отпускания клавиш
void Controller::setReleaseCommand(int key, Command* command) {
    keyReleaseBindings[key] = command;
}