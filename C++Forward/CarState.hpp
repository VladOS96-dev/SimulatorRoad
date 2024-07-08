#ifndef CAR_STATE_HPP
#define CAR_STATE_HPP

class Car;

// ����������� ����� ��������� ������
class CarState {
public:
    virtual ~CarState() = default;

    // ������������ ���� (�������/���������� �������)
    virtual void handleInput(Car& car, int key, int action) = 0;

    // ��������� ��������� ������
    virtual void update(Car& car, float deltaTime) = 0;
};

#endif // CAR_STATE_HPP
