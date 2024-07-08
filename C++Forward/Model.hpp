#ifndef MODEL_HPP
#define MODEL_HPP

#include <cmath>
#include <vector>
#include <string>
#include "Road.hpp"
#include "Car.hpp"
#include <chrono>
#include "UpdateHandler.hpp"

#include <map>
#include <algorithm> 

class UpdateHandler; // Forward declaration

class Model {
public:
    Model(); // ����������� ������

    // ���������� ������
    void update(bool scrollMode, float deltaTime);

    // ��������� ������ �� ����������
    const Car& getCar() const;

    // ��������� ���������
    const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& getMessages() const;

    // ��������� ������
    const Road& getRoad() const;

    // ��������� �������� �������
    const std::chrono::time_point<std::chrono::high_resolution_clock> getCurrentTime();

    // ��������� ���������
    void setMessage(const std::string& key, const std::chrono::time_point<std::chrono::high_resolution_clock>& time);

    // ��������� ����� ����������� �����
    void setCrossingLine(bool value);

    // ��������� �������� ����� ����������� �����
    bool getCrossingLine() const;

    // ��������� ������� �������� ����������
    void setTimeMoveCar(float time);

    // ��������� ������� �������� ����������
    float getTimeMoveCar() const;

    // ��������� ������� ������ ��������
    void setTimeBeginMove(const std::chrono::time_point<std::chrono::high_resolution_clock>& time);

    // ��������� ������� ������ ��������
    const std::chrono::time_point<std::chrono::high_resolution_clock>& getTimeBeginMove() const;

private:
    Road road; // ������
    std::shared_ptr<UpdateHandler> updateHandler; // ���������� ����������
    Car car; // ������ ����������
    std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> messages; // ��������� ������
    bool crossingLine; // ���� ����������� �����
    float timeMoveCar; // ����� �������� ����������
    std::chrono::time_point<std::chrono::high_resolution_clock> timeBeginMove; // ����� ������ ��������

    // ������������� ������������
    void initializeHandlers();
};

#endif // MODEL_HPP

