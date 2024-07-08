#include "Road.hpp"

// ����������� ������ Road
Road::Road() {
    generateRandomLines();
}

// ���������� ������ ���������� �� �����
const std::vector<Line*>& Road::getLines() const {
    return lines;
}

// ���������� ��������� ����� ��� ������
void Road::generateRandomLines() {
    float y = -1.0f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.1f, 0.2f);
    std::uniform_int_distribution<int> type(0, 1);
    while (y < 1.0f) {
        float length = dis(gen);
        if (type(gen) == 0) {
            lines.push_back(new SolidLine(0.0f, y, 0.0f, y + length, 0.1f, "white"));
        }
        else {
            lines.push_back(new DashedLine(0.0f, y, 0.0f, y + length, 0.1f, "white"));
        }
        y += length;
    }
}

// ������������ ����� ������
void Road::render() const {
    for (const Line* line : lines) {
        line->render();
    }
}

// ���������� ������ Road
Road::~Road() {
    for (Line* line : lines) {
        delete line;
    }
}
