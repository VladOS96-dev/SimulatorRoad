#ifndef VIEW_HPP
#define VIEW_HPP

#include <GL/glut.h>
#include <vector>
#include <string>
#include "Model.hpp"
#include "Road.hpp"
#include "Car.hpp"
#include "Controller.hpp"
#include "Utils.hpp"

class Controller;

class View {
private:
    Model* model;
    Controller* controller;

public:
    // ������������� ������ ��� �������������
    void setModel(Model* m);

    // ������������� ���������� ��� �������������
    void setController(Controller* p);

    // ������������ ������� �����: ������, ������ � ���������
    void render(const Car& car, const Road& road, const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& messages);

    // ������ ����� �� ������ � �������� �����������
    void drawText(const char* text, float x, float y);
};

#endif
