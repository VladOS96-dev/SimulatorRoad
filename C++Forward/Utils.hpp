#ifndef UTILS_HPP
#define UTILS_HPP

 class Utils
{
public:
    // Преобразует относительную координату X в пиксельную координату X.
    static float toPixelX(float x);

    // Преобразует относительную координату Y в пиксельную координату Y.
    static float toPixelY(float y);

    // Преобразует пиксельную координату X в относительную координату X.
    static float toRelativeX(float x);

    // Преобразует пиксельную координату Y в относительную координату Y.
    static float toRelativeY(float y);
};

#endif // !UTILS_HPP
