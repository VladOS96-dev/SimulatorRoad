#ifndef TURNING_HANDLER_HPP
#define TURNING_HANDLER_HPP

#include "UpdateHandler.hpp"
#include"Model.hpp"
// �����-���������� ��� �������� ��������� ��������
class TurningHandler : public UpdateHandler {
public:
    // ���������������� ����� ��� ��������� ������
    void handle(Model& model, float deltaTime) override;

};
#endif // TURNING_HANDLER_HPP
