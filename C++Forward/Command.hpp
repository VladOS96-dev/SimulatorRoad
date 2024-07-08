#ifndef COMMAND_HPP
#define COMMAND_HPP

// Абстрактный класс команды
class Command {
public:
    virtual ~Command() = default;

    // Выполняет команду
    virtual void execute() = 0;
};

#endif // COMMAND_HPP
