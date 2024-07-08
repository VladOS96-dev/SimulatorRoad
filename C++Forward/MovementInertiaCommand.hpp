#ifndef MOVEMENT_INERTIA_COMMAND_HPP
#define MOVEMENT_INERTIA_COMMAND_HPP
#include "Command.hpp"
#include "Car.hpp"

// ������� ��� ���������� �������� ������
class MovementInertiaCommand : public Command {
private:
    Car* car;
public:
    MovementInertiaCommand(Car* c) : car(c) {}

    // ��������� �������: ���������� �������� ������
    void execute() override {
        car->inertiaMove();
    }
};
#endif // !MOVEMENT_INERTIA_COMMAND_HPP
