#ifndef ROTATE_LEFT_COMMAND_HPP
#define ROTATE_LEFT_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

//  оманда дл€ поворота машины влево
class RotateLeftCommand : public Command {
private:
    Car* car;
public:
    RotateLeftCommand(Car* c) : car(c) {}

    // ¬ыполн€ет команду: поворачивает машину влево
    void execute() override {
        car->rotateLeft();
        car->startTurn();
    }
};

#endif // ROTATE_LEFT_COMMAND_HPP