#include "Display.hpp"

// ������������� ��������
const char* Display::TITLE_WINDOW = "Road Simulator";
const int Display::WIDTH_WINDOW = 400;
const int Display::HEIGHT_WINDOW = 700;

// ������������� ������������ ��������� �� ��������� ������
Display* Display::instance = nullptr;

// �����������
Display::Display() : modelPtr(nullptr), viewPtr(nullptr), controllerPtr(nullptr) {}

// ����������
Display::~Display()
{
    delete controllerPtr;
    delete viewPtr;
    delete modelPtr;
}

// ������������� GLUT, ���� � �������� ����������� MVC
void Display::init(int argc, char** argv)
{
    instance = this;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH_WINDOW, HEIGHT_WINDOW);
    glutCreateWindow(TITLE_WINDOW);

    modelPtr = new Model();
    viewPtr = new View();
    controllerPtr = new Controller(modelPtr, viewPtr);
    viewPtr->setModel(modelPtr);
    viewPtr->setController(controllerPtr);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // ��������� �������� GLUT
    glutDisplayFunc(displayCallback);
    glutIdleFunc(idleCallback);
    glutSpecialFunc(specialKeyDownCallback);
    glutSpecialUpFunc(specialKeyUpCallback);
}

// ������ ��������� ����� ���������
void Display::draw()
{
    glutMainLoop();
}

// ������ ��� ���������
void Display::displayCallback()
{
    instance->display();
}

// ������ ��� ��������� ������� (idle)
void Display::idleCallback()
{
    instance->idle();
}

// ������ ��� ��������� ������� ����������� ������
void Display::specialKeyDownCallback(int key, int x, int y)
{
    instance->specialKeyDown(key, x, y);
}

// ������ ��� ��������� ���������� ����������� ������
void Display::specialKeyUpCallback(int key, int x, int y)
{
    instance->specialKeyUp(key, x, y);
}

// ��������� ����� � ���������� ��������� �����������
void Display::display()
{
    controllerPtr->update();
    viewPtr->render(modelPtr->getCar(), modelPtr->getRoad(), modelPtr->getMessages());
    glutSwapBuffers();
}

// ��������� ������� (idle), ���������� ����������� � ����������� �����
void Display::idle()
{
    controllerPtr->update();
    glutPostRedisplay();
}

// ��������� ������� ����������� ������
void Display::specialKeyDown(int key, int x, int y)
{
    controllerPtr->onKeyEvent(key, GLUT_DOWN);
}

// ��������� ���������� ����������� ������
void Display::specialKeyUp(int key, int x, int y)
{
    controllerPtr->onKeyEvent(key, GLUT_UP);
}
