#ifndef ROTATE_LEFT_COMMAND_HPP
#define ROTATE_LEFT_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

// ������� ��� �������� ������ �����
class RotateLeftCommand : public Command {
private:
    Car* car;
public:
    RotateLeftCommand(Car* c) : car(c) {}

    // ��������� �������: ������������ ������ �����
    void execute() override {
        car->rotateLeft();
        car->startTurn();
    }
};

#endif // ROTATE_LEFT_COMMAND_HPP