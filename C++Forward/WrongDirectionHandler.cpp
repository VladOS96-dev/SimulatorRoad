#include "WrongDirectionHandler.hpp"
#include "Car.hpp"

void WrongDirectionHandler::handle(Model& model, float deltaTime) {
    Car car = model.getCar();

    // Проверка на выезд на встречную полосу
    if (((car.getX() < 0.0f && car.getCarDirection() == UP) || (car.getX() > 0.0f && car.getCarDirection() == DOWN)) && !model.getCrossingLine()) {
        model.setMessage("Driving in the wrong direction!", model.getCurrentTime());
    }

    // Вызов следующего обработчика, если он есть
    UpdateHandler::handle(model, deltaTime);
}