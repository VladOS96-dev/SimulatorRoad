#ifndef TURNING_HANDLER_HPP
#define TURNING_HANDLER_HPP

#include "UpdateHandler.hpp"
#include"Model.hpp"
// Класс-обработчик для проверки состояния поворота
class TurningHandler : public UpdateHandler {
public:
    // Переопределенный метод для обработки модели
    void handle(Model& model, float deltaTime) override;

};
#endif // TURNING_HANDLER_HPP
