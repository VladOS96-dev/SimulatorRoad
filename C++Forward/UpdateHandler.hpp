#ifndef UPDATE_HANDLER_HPP
#define UPDATE_HANDLER_HPP

#include "Model.hpp"
#include <memory>
class Model;
// ������� ����� ��� ������������ ����������
class UpdateHandler {
public:
    // ����������� ���������� ��� ����������� ����������� �������� �������� ����������� �������
    virtual ~UpdateHandler() = default;

    // ����� ��� ��������� ���������� ����������� � �������
    void setNext(std::shared_ptr<UpdateHandler> nextHandler);

    // ����������� ����� ��� ��������� ������
    // ������ ���� ������������� � ����������� �������
    virtual void handle(Model& model, float deltaTime);

private:
    // ��������� �� ��������� ���������� � �������
    std::shared_ptr<UpdateHandler> next;
};

#endif // UPDATE_HANDLER_HPP
