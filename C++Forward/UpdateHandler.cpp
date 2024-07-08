#include"UpdateHandler.hpp"

// Устанавливает указатель на следующий обработчик в цепочке
// nextHandler: Указатель на следующий обработчик
void UpdateHandler::setNext(std::shared_ptr<UpdateHandler> nextHandler) {
    next = nextHandler;
}

// Обрабатывает модель и передает управление следующему обработчику в цепочке
// model: Ссылка на модель, которую нужно обработать
// deltaTime: Время, прошедшее с предыдущего обновления
void UpdateHandler::handle(Model& model, float deltaTime) {
    // Если существует следующий обработчик, передаем ему управление
    if (next) {
        next->handle(model, deltaTime);
    }
}