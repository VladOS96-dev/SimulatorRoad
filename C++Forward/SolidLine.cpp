#include "SolidLine.hpp"

// ����������� ������ SolidLine
// sx: ��������� ���������� X
// sy: ��������� ���������� Y
// ex: �������� ���������� X
// ey: �������� ���������� Y
// w: ������ �����
// c: ���� �����
SolidLine::SolidLine(float sx, float sy, float ex, float ey, float w, const std::string& c)
    : Line(sx, sy, ex, ey, w, c) {}

// ��������������� ������� render ��� ��������� �������� �����
void SolidLine::render() const {
    glColor3f(1.0f, 1.0f, 1.0f);  // ��������� ����� �����
    glBegin(GL_LINES);  // ������ ��������� �����
    glVertex2f(startX, startY);
    glVertex2f(endX, endY);
    glEnd();  // ����� ��������� �����
}

// ��������������� ������� checkCollision ��� �������� ������������ � �����������
bool SolidLine::checkCollision(const Car& car) const {
    return Line::checkCollision(car);  // ������������� ���������� �� �������� ������ Line
}

// ��������������� ������� getMessage ��� ��������� ��������� � ����������� �������� �����
std::string SolidLine::getMessage() {
    return "You crossed a solid line!";  // ���������� ������ � ����������
}
