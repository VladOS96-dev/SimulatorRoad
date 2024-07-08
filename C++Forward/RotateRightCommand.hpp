#ifndef ROTATE_RIGHT_COMMAND_HPP
#define ROTATE_RIGHT_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

//  оманда дл€ поворота машины вправо
class RotateRightCommand : public Command {
private:
    Car* car;
public:
    RotateRightCommand(Car* c) : car(c) {}

    // ¬ыполн€ет команду: поворачивает машину вправо
    void execute() override {
        car->rotateRight();
        car->startTurn();
    }
};

#endif // ROTATE_RIGHT_COMMAND_HPP
