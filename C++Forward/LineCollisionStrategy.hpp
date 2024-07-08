#ifndef LINE_COLLISION_STRATEGY_HPP
#define LINE_COLLISION_STRATEGY_HPP

#include "CollisionStrategy.hpp"
#include "Line.hpp"
#include "Car.hpp"

// ����� LineCollisionStrategy, ����������� ��������� �������� ������������ � ������
class LineCollisionStrategy : public CollisionStrategy {
private:
    const Line& line;  // ������ �� ������ �����
public:
    // ����������� ������ LineCollisionStrategy
    LineCollisionStrategy(const Line& l) : line(l) {}

    // ��������������� ����������� ������� ��� �������� ������������ � �����������
    bool checkCollision(const Car& car) const override;
};

#endif // LINE_COLLISION_STRATEGY_HPP
