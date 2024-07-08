#include "Display.hpp"

// Инициализация констант
const char* Display::TITLE_WINDOW = "Road Simulator";
const int Display::WIDTH_WINDOW = 400;
const int Display::HEIGHT_WINDOW = 700;

// Инициализация статического указателя на экземпляр класса
Display* Display::instance = nullptr;

// Конструктор
Display::Display() : modelPtr(nullptr), viewPtr(nullptr), controllerPtr(nullptr) {}

// Деструктор
Display::~Display()
{
    delete controllerPtr;
    delete viewPtr;
    delete modelPtr;
}

// Инициализация GLUT, окна и основных компонентов MVC
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

    // Установка колбэков GLUT
    glutDisplayFunc(displayCallback);
    glutIdleFunc(idleCallback);
    glutSpecialFunc(specialKeyDownCallback);
    glutSpecialUpFunc(specialKeyUpCallback);
}

// Запуск основного цикла отрисовки
void Display::draw()
{
    glutMainLoop();
}

// Колбэк для отрисовки
void Display::displayCallback()
{
    instance->display();
}

// Колбэк для обработки простоя (idle)
void Display::idleCallback()
{
    instance->idle();
}

// Колбэк для обработки нажатия специальных клавиш
void Display::specialKeyDownCallback(int key, int x, int y)
{
    instance->specialKeyDown(key, x, y);
}

// Колбэк для обработки отпускания специальных клавиш
void Display::specialKeyUpCallback(int key, int x, int y)
{
    instance->specialKeyUp(key, x, y);
}

// Отрисовка сцены и обновление состояния контроллера
void Display::display()
{
    controllerPtr->update();
    viewPtr->render(modelPtr->getCar(), modelPtr->getRoad(), modelPtr->getMessages());
    glutSwapBuffers();
}

// Обработка простоя (idle), обновление контроллера и перерисовка сцены
void Display::idle()
{
    controllerPtr->update();
    glutPostRedisplay();
}

// Обработка нажатия специальных клавиш
void Display::specialKeyDown(int key, int x, int y)
{
    controllerPtr->onKeyEvent(key, GLUT_DOWN);
}

// Обработка отпускания специальных клавиш
void Display::specialKeyUp(int key, int x, int y)
{
    controllerPtr->onKeyEvent(key, GLUT_UP);
}
