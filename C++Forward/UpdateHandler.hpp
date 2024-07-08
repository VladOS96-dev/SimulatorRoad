#ifndef UPDATE_HANDLER_HPP
#define UPDATE_HANDLER_HPP

#include "Model.hpp"
#include <memory>
class Model;
// Базовый класс для обработчиков обновлений
class UpdateHandler {
public:
    // Виртуальный деструктор для обеспечения корректного удаления объектов производных классов
    virtual ~UpdateHandler() = default;

    // Метод для установки следующего обработчика в цепочке
    void setNext(std::shared_ptr<UpdateHandler> nextHandler);

    // Виртуальный метод для обработки модели
    // Должен быть переопределен в производных классах
    virtual void handle(Model& model, float deltaTime);

private:
    // Указатель на следующий обработчик в цепочке
    std::shared_ptr<UpdateHandler> next;
};

#endif // UPDATE_HANDLER_HPP
