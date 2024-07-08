#ifndef SOLID_LINE_HPP
#define SOLID_LINE_HPP

#include "Line.hpp"

// Класс SolidLine, представляющий сплошную линию, наследуемый от Line
class SolidLine : public Line {
public:
    // Конструктор класса SolidLine
    SolidLine(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // Переопределение виртуальной функции для отрисовки сплошной линии
    void render() const override;

    // Переопределение виртуальной функции для проверки столкновения с автомобилем
    bool checkCollision(const Car& car) const override;

    // Переопределение виртуальной функции для получения сообщения о пересечении сплошной линии
    std::string getMessage() override;
};

#endif // !SOLID_LINE_HPP
