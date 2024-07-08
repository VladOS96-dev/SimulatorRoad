#ifndef BRAKING_COMMAND_HPP
#define BRAKING_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

//  оманда дл€ уменьшени€ скорости машины
class BrakingCommand : public Command {
private:
    Car* car;
public:
    BrakingCommand(Car* c) : car(c) {}

    // ¬ыполн€ет команду: уменьшени€ скорость машины
    void execute() override {
        car->decreaseSpeed();
    }
};

#endif // BRAKING_COMMAND_HPP