#include"TurningHandler.hpp"

// ���������������� ����� ��� ��������� ������
// ��������� ��������� �������� ������ � ��������� ��������������� ���������
void TurningHandler::handle(Model& model, float deltaTime) {
    auto currentTime = std::chrono::high_resolution_clock::now();

    // ��������, ����������� �� ������� ������
    if (model.getCar().getTurning()) {
        // ���������� ��������� � ������ ��������

        model.setMessage("Turning...", currentTime);

        // �������� ���� ��������
        float angle = fabs(fmod(model.getCar().getAngle(), 360.0f));
        if ((angle >= 80.0f && angle <= 100) || (angle >= 260.0f && angle <= 280)) {
            // ���������� ��������� �� �������� ��������

            model.setMessage("Turn successful!", currentTime);
        }
    }

    // �������� ���������� ���������� �����������
    UpdateHandler::handle(model, deltaTime);
}