#include "Line.hpp"
#include"LineCollisionStrategy.hpp"

// Конструктор класса Line
Line::Line(float sx, float sy, float ex, float ey, float w, const std::string& c)
    : startX(sx), startY(sy), endX(ex), endY(ey), width(w), solid(c) {}

// Реализация функции render для отрисовки линии
void Line::render() const {
    float relativeStartX = Utils::toRelativeX(startX);
    float relativeStartY = Utils::toRelativeX(startY);
    float relativeEndX = Utils::toRelativeX(endX);
    float relativeEndY = Utils::toRelativeX(endY);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(startX, startY);
    glVertex2f(endX, endY);
    glEnd();
}

// Реализация функции checkCollision для проверки столкновения с автомобилем
bool Line::checkCollision(const Car& car) const {
    LineCollisionStrategy strategy(*this);
    return strategy.checkCollision(car);
}

float Line::getStartX() const
{
    return startX;
}

float Line::getStartY() const
{
    return startY;
}

float Line::getEndX() const
{
    return endX;
}

float Line::getEndY() const
{
    return endY;
}

float Line::getWidth() const
{
    return width;
}

std::string Line::getSolid() const
{
    return solid;
}

void Line::setStartX(float sx)
{
    startX = sx;
}

void Line::setStartY(float sy)
{
    startY = sy;
}

void Line::setEndX(float ex)
{
    endX = ex;
}

void Line::setEndY(float ey)
{
    endY = ey;
}

void Line::setWidth(float w)
{
    width = w;
}

void Line::setSolid(const std::string& c)
{
    solid = c;
}


