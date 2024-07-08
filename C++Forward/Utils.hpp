#ifndef UTILS_HPP
#define UTILS_HPP

 class Utils
{
public:
    // ����������� ������������� ���������� X � ���������� ���������� X.
    static float toPixelX(float x);

    // ����������� ������������� ���������� Y � ���������� ���������� Y.
    static float toPixelY(float y);

    // ����������� ���������� ���������� X � ������������� ���������� X.
    static float toRelativeX(float x);

    // ����������� ���������� ���������� Y � ������������� ���������� Y.
    static float toRelativeY(float y);
};

#endif // !UTILS_HPP
