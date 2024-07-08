#include"LineCrossingHandler.hpp"


// Переопределенный метод для обработки модели
// Проверяет пересечение линий и обновляет состояние модели
void LineCrossingHandler::handle(Model& model, float deltaTime) {
    auto currentTime = std::chrono::high_resolution_clock::now();

    // Проверка пересечения машины с каждой линией
    for (auto& line : model.getRoad().getLines()) {
        if (line->checkCollision(model.getCar())) {
            // Добавление сообщения о пересечении линии
            model.setMessage(line->getMessage(), currentTime);
            model.setCrossingLine(true);
            model.setTimeBeginMove(currentTime);
        }
    }

    // Проверка времени нахождения на линии
    if (model.getCrossingLine()) {
        std::chrono::duration<float> timeMove = currentTime - model.getTimeBeginMove();
        if (timeMove.count() > model.getTimeMoveCar()) {
            model.setCrossingLine(false)  ;
        }
    }

    // Передача управления следующему обработчику
    UpdateHandler::handle(model, deltaTime);
}