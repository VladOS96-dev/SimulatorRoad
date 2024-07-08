#ifndef ROAD_HPP
#define ROAD_HPP

#include <vector>
#include <GL/glut.h>
#include "Line.hpp"
#include <random>
#include "DashedLine.hpp"
#include "SolidLine.hpp"

class Road {
public:
    // Конструктор класса Road
    Road();

    // Возвращает вектор указателей на линии
    const std::vector<Line*>& getLines() const;

    // Генерирует случайные линии для дороги
    void generateRandomLines();

    // Отрисовывает линии дороги
    void render() const;

    // Деструктор класса Road
    ~Road();

private:
    // Вектор указателей на линии
    std::vector<Line*> lines;
};

#endif