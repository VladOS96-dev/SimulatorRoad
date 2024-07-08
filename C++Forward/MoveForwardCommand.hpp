#ifndef MOVE_FORWARD_COMMAND_HPP
#define MOVE_FORWARD_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

// ������� ��� ���������� �������� ������
class MoveForwardCommand : public Command {
private:
    Car* car;
public:
    MoveForwardCommand(Car* c) : car(c) {}

    // ��������� �������: ����������� �������� ������
    void execute() override {
        car->increaseSpeed();
    }
};

#endif // MOVE_FORWARD_COMMAND_HPP