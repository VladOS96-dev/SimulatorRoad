#ifndef LINE_HPP
#define LINE_HPP

#include <GL/glut.h>
#include "Car.hpp"
#include "Utils.hpp"
#include <string>

class Line {
public:
    // Конструктор класса Line
    Line(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // Чисто виртуальная функция для отрисовки линии
    virtual void render() const = 0;

    // Чисто виртуальная функция для проверки столкновения с автомобилем
    virtual bool checkCollision(const Car& car) const = 0;

    // Чисто виртуальная функция для получения сообщения о пересечении линии
    virtual std::string getMessage() = 0;

    // Методы доступа (getters) для переменных класса Line
    float getStartX() const;
    float getStartY() const; 
    float getEndX() const; 
    float getEndY() const; 
    float getWidth() const; 
    std::string getSolid() const; 

    // Методы установки (setters) для переменных класса Line
    void setStartX(float sx);
    void setStartY(float sy);
    void setEndX(float ex);
    void setEndY(float ey); 
    void setWidth(float w);
    void setSolid(const std::string& c); 

protected:
    // Переменные класса Line
    float startX, startY, endX, endY, width;
    std::string solid;
};

#endif // LINE_HPP
