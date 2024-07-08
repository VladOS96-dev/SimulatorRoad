#ifndef STOP_ROTATE_COMMAND_HPP
#define STOP_ROTATE_COMMAND_HPP

#include "Command.hpp"
#include "Car.hpp"

// Команда для остановки вращения
class StopRotateCommand : public Command {
private:
    Car* car;
public:
    StopRotateCommand(Car* c) : car(c) {}

    // Выполняет команду: остановки вращения
    void execute() override {
        car->stopTurn();
    }
};

#endif // STOP_ROTATE_COMMAND_HPP