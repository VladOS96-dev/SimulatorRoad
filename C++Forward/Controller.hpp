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

// ����� Controller ��� ���������� �������
class Controller {
private:
    Model* model;
    View* view;
    bool scrollMode;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;
    std::map<int, Command*> keyBindings;  // ����� ����� ��������� � ���������
    std::map<int, Command*> keyReleaseBindings;  // ����� ����� ��������� � ��������� ��� ����������

public:
    Controller(Model* m, View* v);

    // ������������ ������� ������
    void onKeyEvent(int key, int action);

    // ��������� ��������� ������
    void update();

    // ������������� ������� ��� ������
    void setCommand(int key, Command* command);
    // ������������� ������� ��� ���������� ������
    void setReleaseCommand(int key, Command* command);
};

#endif // CONTROLLER_HPP