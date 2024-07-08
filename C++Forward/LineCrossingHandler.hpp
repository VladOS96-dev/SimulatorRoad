#ifndef LINE_CROSSING_HANDLER_HPP
#define LINE_CROSSING_HANDLER_HPP

#include "UpdateHandler.hpp"
#include"Model.hpp"
// �����-���������� ��� �������� ����������� �����
class LineCrossingHandler : public UpdateHandler {
public:
    // ���������������� ����� ��� ��������� ������
    void handle(Model& model, float deltaTime) override;
};

#endif // LINE_CROSSING_HANDLER_HPP
