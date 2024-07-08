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
    // ����������� ������ Road
    Road();

    // ���������� ������ ���������� �� �����
    const std::vector<Line*>& getLines() const;

    // ���������� ��������� ����� ��� ������
    void generateRandomLines();

    // ������������ ����� ������
    void render() const;

    // ���������� ������ Road
    ~Road();

private:
    // ������ ���������� �� �����
    std::vector<Line*> lines;
};

#endif