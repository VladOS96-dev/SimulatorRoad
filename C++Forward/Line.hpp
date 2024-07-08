#ifndef LINE_HPP
#define LINE_HPP

#include <GL/glut.h>
#include "Car.hpp"
#include "Utils.hpp"
#include <string>

class Line {
public:
    // ����������� ������ Line
    Line(float sx, float sy, float ex, float ey, float w, const std::string& c);

    // ����� ����������� ������� ��� ��������� �����
    virtual void render() const = 0;

    // ����� ����������� ������� ��� �������� ������������ � �����������
    virtual bool checkCollision(const Car& car) const = 0;

    // ����� ����������� ������� ��� ��������� ��������� � ����������� �����
    virtual std::string getMessage() = 0;

    // ������ ������� (getters) ��� ���������� ������ Line
    float getStartX() const;
    float getStartY() const; 
    float getEndX() const; 
    float getEndY() const; 
    float getWidth() const; 
    std::string getSolid() const; 

    // ������ ��������� (setters) ��� ���������� ������ Line
    void setStartX(float sx);
    void setStartY(float sy);
    void setEndX(float ex);
    void setEndY(float ey); 
    void setWidth(float w);
    void setSolid(const std::string& c); 

protected:
    // ���������� ������ Line
    float startX, startY, endX, endY, width;
    std::string solid;
};

#endif // LINE_HPP
