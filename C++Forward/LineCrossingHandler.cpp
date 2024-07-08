#include"LineCrossingHandler.hpp"


// ���������������� ����� ��� ��������� ������
// ��������� ����������� ����� � ��������� ��������� ������
void LineCrossingHandler::handle(Model& model, float deltaTime) {
    auto currentTime = std::chrono::high_resolution_clock::now();

    // �������� ����������� ������ � ������ ������
    for (auto& line : model.getRoad().getLines()) {
        if (line->checkCollision(model.getCar())) {
            // ���������� ��������� � ����������� �����
            model.setMessage(line->getMessage(), currentTime);
            model.setCrossingLine(true);
            model.setTimeBeginMove(currentTime);
        }
    }

    // �������� ������� ���������� �� �����
    if (model.getCrossingLine()) {
        std::chrono::duration<float> timeMove = currentTime - model.getTimeBeginMove();
        if (timeMove.count() > model.getTimeMoveCar()) {
            model.setCrossingLine(false)  ;
        }
    }

    // �������� ���������� ���������� �����������
    UpdateHandler::handle(model, deltaTime);
}