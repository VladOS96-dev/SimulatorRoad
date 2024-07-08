#ifndef LINE_CROSSING_HANDLER_HPP
#define LINE_CROSSING_HANDLER_HPP

#include "UpdateHandler.hpp"
#include"Model.hpp"
// Класс-обработчик для проверки пересечения линий
class LineCrossingHandler : public UpdateHandler {
public:
    // Переопределенный метод для обработки модели
    void handle(Model& model, float deltaTime) override;
};

#endif // LINE_CROSSING_HANDLER_HPP
