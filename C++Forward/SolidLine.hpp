#ifndef SOLID_LINE_HPP
#define SOLID_LINE_HPP

#include "Line.hpp"

// ����� SolidLine, �������������� �������� �����, ����������� �� Line
class SolidLine : public Line {
public:
    // ����������� ������ SolidLine
    SolidLine(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // ��������������� ����������� ������� ��� ��������� �������� �����
    void render() const override;

    // ��������������� ����������� ������� ��� �������� ������������ � �����������
    bool checkCollision(const Car& car) const override;

    // ��������������� ����������� ������� ��� ��������� ��������� � ����������� �������� �����
    std::string getMessage() override;
};

#endif // !SOLID_LINE_HPP
