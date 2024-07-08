#include "DashedLine.hpp"

// ����������� ������ DashedLine
// sx: ��������� ���������� X
// sy: ��������� ���������� Y
// ex: �������� ���������� X
// ey: �������� ���������� Y
// w: ������ �����
// c: ���� �����
DashedLine::DashedLine(float sx, float sy, float ex, float ey, float w, const std::string& c)
    : Line(sx, sy, ex, ey, w, c) {}

// ��������� ���������� �����
void DashedLine::render() const {
    glColor3f(1.0f, 1.0f, 1.0f);  // ��������� ����� �����
    glBegin(GL_LINES);  // ������ ��������� �����
    for (float y = startY; y < endY; y += 0.04f) {  // ��������� ���������
        glVertex2f(startX, y);
        glVertex2f(startX, y + 0.02f);
    }
    glEnd();  // ����� ��������� �����
}

// �������� ������������ � ����������� (���������� ���������� �� �������� ������)
bool DashedLine::checkCollision(const Car& car) const {
    return Line::checkCollision(car);
}

// ��������� ��������� � ����������� �����
// ���������� ������ � ����������
std::string DashedLine::getMessage() {
    return "You crossed a dashed line!";
}
