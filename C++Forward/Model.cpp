#include "Model.hpp"
#include "LineCrossingHandler.hpp"
#include "TurningHandler.hpp"
#include "WrongDirectionHandler.hpp"

Model::Model()
    : crossingLine(false), timeMoveCar(2.0f)
{
    initializeHandlers(); // Инициализация обработчиков при создании модели
}

void Model::update(bool scrollMode, float deltaTime) {
    car.update(deltaTime); // Обновление состояния автомобиля
    auto currentTime = std::chrono::high_resolution_clock::now();

    // Удаление старых сообщений
    for (auto it = messages.begin(); it != messages.end(); ) {
        std::chrono::duration<float> timeMessage = currentTime - it->second;
        if (timeMessage.count() > 1.0f) {
            it = messages.erase(it); // Удаление старого сообщения, если оно устарело
        }
        else {
            ++it;
        }
    }

    updateHandler->handle(*this, deltaTime); // Обработка обновлений через цепочку обработчиков

}

 const Car& Model::getCar() const {
    return car; // Возвращает ссылку на автомобиль
}

const std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>& Model::getMessages() const {
    return messages; // Возвращает сообщения модели
}

const Road& Model::getRoad() const {
    return road; // Возвращает дорогу
}

const std::chrono::time_point<std::chrono::high_resolution_clock> Model::getCurrentTime() {
    return std::chrono::high_resolution_clock::now(); // Возвращает текущее время
}
// Установка сообщения
void Model::setMessage(const std::string& key, const std::chrono::time_point<std::chrono::high_resolution_clock>& time)
{
    messages.emplace(key,time);
}

void Model::initializeHandlers() {
    // Создание обработчиков для пересечения линии, поворотов и встречной полосы
    auto lineCrossingHandler = std::make_shared<LineCrossingHandler>();
    auto turningHandler = std::make_shared<TurningHandler>();
    auto wrongDirectionHandler = std::make_shared<WrongDirectionHandler>();

    // Установка связей между обработчиками
    lineCrossingHandler->setNext(wrongDirectionHandler);
    wrongDirectionHandler->setNext(turningHandler);

    // Установка начального обработчика для модели
    updateHandler = lineCrossingHandler;
}
// Установка флага пересечения линии
void Model::setCrossingLine(bool value)
{
    crossingLine = value;
}
// Получение значения флага пересечения линии
bool Model::getCrossingLine() const
{
    return crossingLine;
}
// Установка времени движения автомобиля
void Model::setTimeMoveCar(float time)
{
    this->timeMoveCar = time;
}
// Получение времени движения автомобиля
float Model::getTimeMoveCar() const
{
    return timeMoveCar;
}
// Установка времени начала движения
void Model::setTimeBeginMove(const std::chrono::time_point<std::chrono::high_resolution_clock>& time)
{
    timeBeginMove = time;
}
// Получение времени начала движения
const std::chrono::time_point<std::chrono::high_resolution_clock>& Model::getTimeBeginMove() const
{
    return timeBeginMove;
}
