#include "Utils.hpp"
#include "Display.hpp"

// ѕреобразует относительную координату X в пиксельную координату X.
// »спользует ширину окна из класса Display.
float Utils::toPixelX(float x) {
    return x * static_cast<float>(Display::WIDTH_WINDOW) * 0.001f;
}

// ѕреобразует относительную координату Y в пиксельную координату Y.
// »спользует высоту окна из класса Display.
float Utils::toPixelY(float y) {
    return y * static_cast<float>(Display::HEIGHT_WINDOW) * 0.001f;
}

// ѕреобразует пиксельную координату X в относительную координату X.
// »спользует ширину окна из класса Display.
float Utils::toRelativeX(float x) {
    return x / static_cast<float>(Display::WIDTH_WINDOW);
}

// ѕреобразует пиксельную координату Y в относительную координату Y.
// »спользует высоту окна из класса Display.
float Utils::toRelativeY(float y) {
    return y / static_cast<float>(Display::HEIGHT_WINDOW);
}
