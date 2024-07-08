#ifndef MOVEMENT_INERTIA_COMMAND_HPP
#define MOVEMENT_INERTIA_COMMAND_HPP
#include "Command.hpp"
#include "Car.hpp"

//  оманда дл€ уменьшени€ скорости машины
class MovementInertiaCommand : public Command {
private:
    Car* car;
public:
    MovementInertiaCommand(Car* c) : car(c) {}

    // ¬ыполн€ет команду: уменьшени€ скорость машины
    void execute() override {
        car->inertiaMove();
    }
};
#endif // !MOVEMENT_INERTIA_COMMAND_HPP
