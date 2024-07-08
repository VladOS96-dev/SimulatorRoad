#include "WrongDirectionHandler.hpp"
#include "Car.hpp"

void WrongDirectionHandler::handle(Model& model, float deltaTime) {
    Car car = model.getCar();

    // �������� �� ����� �� ��������� ������
    if (((car.getX() < 0.0f && car.getCarDirection() == UP) || (car.getX() > 0.0f && car.getCarDirection() == DOWN)) && !model.getCrossingLine()) {
        model.setMessage("Driving in the wrong direction!", model.getCurrentTime());
    }

    // ����� ���������� �����������, ���� �� ����
    UpdateHandler::handle(model, deltaTime);
}