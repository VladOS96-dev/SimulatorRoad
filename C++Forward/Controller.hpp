#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <chrono>
#include "Model.hpp"
#include "View.hpp"
#include "LineCollisionStrategy.hpp"
#include "Command.hpp"
#include <map>

class View;
class Model;

// Класс Controller для управления машиной
class Controller {
private:
    Model* model;
    View* view;
    bool scrollMode;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;
    std::map<int, Command*> keyBindings;  // Связи между клавишами и командами
    std::map<int, Command*> keyReleaseBindings;  // Связи между клавишами и командами при отпускании

public:
    Controller(Model* m, View* v);

    // Обрабатывает события клавиш
    void onKeyEvent(int key, int action);

    // Обновляет состояние машины
    void update();

    // Устанавливает команды для клавиш
    void setCommand(int key, Command* command);
    // Устанавливает команды для отпускания клавиш
    void setReleaseCommand(int key, Command* command);
};

#endif // CONTROLLER_HPP