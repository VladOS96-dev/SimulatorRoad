#ifndef DASHED_LINE_HPP
#define DASHED_LINE_HPP

#include "Line.hpp"

// Класс DashedLine, представляющий пунктирную линию, наследуемый от Line
class DashedLine : public Line {
public:
    // Конструктор класса DashedLine
    DashedLine(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // Отрисовка пунктирной линии (переопределение виртуальной функции render из базового класса)
    void render() const override;

    // Проверка столкновения с автомобилем (использует реализацию из базового класса)
    bool checkCollision(const Car& car) const override;

    // Получение сообщения о пересечении линии (переопределение виртуальной функции getMessage из базового класса)
    std::string getMessage() override;
};

#endif // !DASHED_LINE_HPP
