#include "DashedLine.hpp"

// Конструктор класса DashedLine
// sx: начальная координата X
// sy: начальная координата Y
// ex: конечная координата X
// ey: конечная координата Y
// w: ширина линии
// c: цвет линии
DashedLine::DashedLine(float sx, float sy, float ex, float ey, float w, const std::string& c)
    : Line(sx, sy, ex, ey, w, c) {}

// Отрисовка пунктирной линии
void DashedLine::render() const {
    glColor3f(1.0f, 1.0f, 1.0f);  // Установка цвета линии
    glBegin(GL_LINES);  // Начало рисования линий
    for (float y = startY; y < endY; y += 0.04f) {  // Отрисовка пунктиров
        glVertex2f(startX, y);
        glVertex2f(startX, y + 0.02f);
    }
    glEnd();  // Конец рисования линий
}

// Проверка столкновения с автомобилем (использует реализацию из базового класса)
bool DashedLine::checkCollision(const Car& car) const {
    return Line::checkCollision(car);
}

// Получение сообщения о пересечении линии
// Возвращает строку с сообщением
std::string DashedLine::getMessage() {
    return "You crossed a dashed line!";
}
