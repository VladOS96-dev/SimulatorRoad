#include "Model.hpp"
#include "LineCrossingHandler.hpp"
#include "TurningHandler.hpp"
#include "WrongDirectionHandler.hpp"

Model::Model()
    : crossingLine(false), timeMoveCar(2.0f)
{
    initializeHandlers(); // ������������� ������������ ��� �������� ������
}

void Model::update(bool scrollMode, float deltaTime) {
    car.update(deltaTime); // ���������� ��������� ����������
    auto currentTime = std::chrono::high_resolution_clock::now();

    // �������� ������ ���������
    for (auto it = messages.begin(); it != messages.end(); ) {
        std::chrono::duration<float> timeMessage = currentTime - it->second;
        if (timeMessage.count() > 1.0f) {
            it = messages.erase(it); // �������� ������� ���������, ���� ��� ��������
        }
        else {
            ++it;
        }
    }

    updateHandler->handle(*this, deltaTime); // ��������� ���������� ����� ������� ������������

}

 const Car& Model::getCar() const {
    return car; // ���������� ������ �� ����������
}

const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& Model::getMessages() const {
    return messages; // ���������� ��������� ������
}

const Road& Model::getRoad() const {
    return road; // ���������� ������
}

const std::chrono::time_point<std::chrono::high_resolution_clock> Model::getCurrentTime() {
    return std::chrono::high_resolution_clock::now(); // ���������� ������� �����
}
// ��������� ���������
void Model::setMessage(const std::string& key, const std::chrono::time_point<std::chrono::high_resolution_clock>& time)
{
    messages.emplace(key,time);
}

void Model::initializeHandlers() {
    // �������� ������������ ��� ����������� �����, ��������� � ��������� ������
    auto lineCrossingHandler = std::make_shared<LineCrossingHandler>();
    auto turningHandler = std::make_shared<TurningHandler>();
    auto wrongDirectionHandler = std::make_shared<WrongDirectionHandler>();

    // ��������� ������ ����� �������������
    lineCrossingHandler->setNext(wrongDirectionHandler);
    wrongDirectionHandler->setNext(turningHandler);

    // ��������� ���������� ����������� ��� ������
    updateHandler = lineCrossingHandler;
}
// ��������� ����� ����������� �����
void Model::setCrossingLine(bool value)
{
    crossingLine = value;
}
// ��������� �������� ����� ����������� �����
bool Model::getCrossingLine() const
{
    return crossingLine;
}
// ��������� ������� �������� ����������
void Model::setTimeMoveCar(float time)
{
    this->timeMoveCar = time;
}
// ��������� ������� �������� ����������
float Model::getTimeMoveCar() const
{
    return timeMoveCar;
}
// ��������� ������� ������ ��������
void Model::setTimeBeginMove(const std::chrono::time_point<std::chrono::high_resolution_clock>& time)
{
    timeBeginMove = time;
}
// ��������� ������� ������ ��������
const std::chrono::time_point<std::chrono::high_resolution_clock>& Model::getTimeBeginMove() const
{
    return timeBeginMove;
}
