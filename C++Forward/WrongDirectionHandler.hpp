#ifndef WRONG_DIRECTION_HANDLER_HPP
#define WRONG_DIRECTION_HANDLER_HPP

#include "UpdateHandler.hpp"

class WrongDirectionHandler : public UpdateHandler {
public:
    // ���������� ��� �������� � ��������� �������� �� ��������� ������
    void handle(Model& model, float deltaTime) override;
};

#endif // WRONG_DIRECTION_HANDLER_HPP