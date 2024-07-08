#ifndef COLLISION_STRATEGY_HPP
#define COLLISION_STRATEGY_HPP

#include "Car.hpp"
class Car;
// ����������� ����� CollisionStrategy ��� ��������� �������� ������������
class CollisionStrategy {
public:
    // ����������� ������� ��� �������� ������������ � �����������
    virtual bool checkCollision(const Car& car) const = 0;

    // ����������� ���������� ��� ����������� ���������� �������
    virtual ~CollisionStrategy() = default;
};

#endif // COLLISION_STRATEGY_HPP
