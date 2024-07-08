#include "SolidLine.hpp"

// Конструктор класса SolidLine
// sx: начальная координата X
// sy: начальная координата Y
// ex: конечная координата X
// ey: конечная координата Y
// w: ширина линии
// c: цвет линии
SolidLine::SolidLine(float sx, float sy, float ex, float ey, float w, const std::string& c)
    : Line(sx, sy, ex, ey, w, c) {}

// Переопределение функции render для отрисовки сплошной линии
void SolidLine::render() const {
    glColor3f(1.0f, 1.0f, 1.0f);  // Установка цвета линии
    glBegin(GL_LINES);  // Начало рисования линий
    glVertex2f(startX, startY);
    glVertex2f(endX, endY);
    glEnd();  // Конец рисования линий
}

// Переопределение функции checkCollision для проверки столкновения с автомобилем
bool SolidLine::checkCollision(const Car& car) const {
    return Line::checkCollision(car);  // Использование реализации из базового класса Line
}

// Переопределение функции getMessage для получения сообщения о пересечении сплошной линии
std::string SolidLine::getMessage() {
    return "You crossed a solid line!";  // Возвращает строку с сообщением
}
