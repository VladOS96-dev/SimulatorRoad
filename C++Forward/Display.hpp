#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <GL/glut.h>
#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

class Display
{
public:
    // ��������� ��� ��������� ����, ������ � ������ ����
    static const char* TITLE_WINDOW;
    static const int WIDTH_WINDOW;
    static const int HEIGHT_WINDOW;

    // �����������
    Display();

    // ����������
    ~Display();

    // ������������� ���� � �������� �����������
    void init(int argc, char** argv);

    // ������ ��������� ����� ���������
    void draw();

private:
    Model* modelPtr;
    View* viewPtr;
    Controller* controllerPtr;

    // ��������� �� ������� ��������� ������ Display
    static Display* instance;

    // ������� ��� GLUT
    static void displayCallback();
    static void idleCallback();
    static void specialKeyDownCallback(int key, int x, int y);
    static void specialKeyUpCallback(int key, int x, int y);

    // �������� ������� ��� ��������� �������, ���������� ����� �������
    void display();
    void idle();
    void specialKeyDown(int key, int x, int y);
    void specialKeyUp(int key, int x, int y);
};

#endif // DISPLAY_HPP
