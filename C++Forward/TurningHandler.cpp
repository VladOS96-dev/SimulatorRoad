#include"TurningHandler.hpp"

// ѕереопределенный метод дл€ обработки модели
// ѕровер€ет состо€ние поворота машины и обновл€ет соответствующие сообщени€
void TurningHandler::handle(Model& model, float deltaTime) {
    auto currentTime = std::chrono::high_resolution_clock::now();

    // ѕроверка, выполн€етс€ ли поворот машины
    if (model.getCar().getTurning()) {
        // ƒобавление сообщени€ о начале поворота

        model.setMessage("Turning...", currentTime);

        // ѕроверка угла поворота
        float angle = fabs(fmod(model.getCar().getAngle(), 360.0f));
        if ((angle >= 80.0f && angle <= 100) || (angle >= 260.0f && angle <= 280)) {
            // ƒобавление сообщени€ об успешном повороте

            model.setMessage("Turn successful!", currentTime);
        }
    }

    // ѕередача управлени€ следующему обработчику
    UpdateHandler::handle(model, deltaTime);
}