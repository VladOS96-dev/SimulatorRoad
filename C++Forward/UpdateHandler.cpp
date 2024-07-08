#include"UpdateHandler.hpp"

// ������������� ��������� �� ��������� ���������� � �������
// nextHandler: ��������� �� ��������� ����������
void UpdateHandler::setNext(std::shared_ptr<UpdateHandler> nextHandler) {
    next = nextHandler;
}

// ������������ ������ � �������� ���������� ���������� ����������� � �������
// model: ������ �� ������, ������� ����� ����������
// deltaTime: �����, ��������� � ����������� ����������
void UpdateHandler::handle(Model& model, float deltaTime) {
    // ���� ���������� ��������� ����������, �������� ��� ����������
    if (next) {
        next->handle(model, deltaTime);
    }
}