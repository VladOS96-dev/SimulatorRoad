#include "Utils.hpp"
#include "Display.hpp"

// ����������� ������������� ���������� X � ���������� ���������� X.
// ���������� ������ ���� �� ������ Display.
float Utils::toPixelX(float x) {
    return x * static_cast<float>(Display::WIDTH_WINDOW) * 0.001f;
}

// ����������� ������������� ���������� Y � ���������� ���������� Y.
// ���������� ������ ���� �� ������ Display.
float Utils::toPixelY(float y) {
    return y * static_cast<float>(Display::HEIGHT_WINDOW) * 0.001f;
}

// ����������� ���������� ���������� X � ������������� ���������� X.
// ���������� ������ ���� �� ������ Display.
float Utils::toRelativeX(float x) {
    return x / static_cast<float>(Display::WIDTH_WINDOW);
}

// ����������� ���������� ���������� Y � ������������� ���������� Y.
// ���������� ������ ���� �� ������ Display.
float Utils::toRelativeY(float y) {
    return y / static_cast<float>(Display::HEIGHT_WINDOW);
}
