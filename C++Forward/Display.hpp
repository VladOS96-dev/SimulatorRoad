#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <GL/glut.h>
#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

class Display
{
public:
    // Константы для заголовка окна, ширины и высоты окна
    static const char* TITLE_WINDOW;
    static const int WIDTH_WINDOW;
    static const int HEIGHT_WINDOW;

    // Конструктор
    Display();

    // Деструктор
    ~Display();

    // Инициализация окна и основных компонентов
    void init(int argc, char** argv);

    // Запуск основного цикла отрисовки
    void draw();

private:
    Model* modelPtr;
    View* viewPtr;
    Controller* controllerPtr;

    // Указатель на текущий экземпляр класса Display
    static Display* instance;

    // Колбэки для GLUT
    static void displayCallback();
    static void idleCallback();
    static void specialKeyDownCallback(int key, int x, int y);
    static void specialKeyUpCallback(int key, int x, int y);

    // Реальные функции для обработки событий, вызываемые через колбэки
    void display();
    void idle();
    void specialKeyDown(int key, int x, int y);
    void specialKeyUp(int key, int x, int y);
};

#endif // DISPLAY_HPP
