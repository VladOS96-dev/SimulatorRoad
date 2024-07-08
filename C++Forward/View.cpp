#include "View.hpp"

// Устанавливает модель для представления
void View::setModel(Model* m) {
    model = m;
}

// Устанавливает контроллер для представления
void View::setController(Controller* p) {
    controller = p;
}

// Отрисовывает текущую сцену: машину, дорогу и сообщения
void View::render(const Car& car, const Road& road, const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& messages) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Отрисовка дороги
    road.render();

    // Отрисовка машины
    car.render();

    // Отрисовка сообщений
    glColor3f(1.0f, 1.0f, 1.0f);
    float offsetY = 0.9f;
    for (const auto& message : messages) {
        drawText(message.first.c_str(), -0.9f, offsetY);
        offsetY -= 0.1f;
    }

    glutSwapBuffers();
}

// Рисует текст на экране в заданных координатах
void View::drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        ++text;
    }
}
