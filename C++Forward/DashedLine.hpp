#ifndef DASHED_LINE_HPP
#define DASHED_LINE_HPP

#include "Line.hpp"

// ����� DashedLine, �������������� ���������� �����, ����������� �� Line
class DashedLine : public Line {
public:
    // ����������� ������ DashedLine
    DashedLine(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // ��������� ���������� ����� (��������������� ����������� ������� render �� �������� ������)
    void render() const override;

    // �������� ������������ � ����������� (���������� ���������� �� �������� ������)
    bool checkCollision(const Car& car) const override;

    // ��������� ��������� � ����������� ����� (��������������� ����������� ������� getMessage �� �������� ������)
    std::string getMessage() override;
};

#endif // !DASHED_LINE_HPP
