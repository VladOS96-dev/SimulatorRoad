#ifndef CAR_STATE_HPP
#define CAR_STATE_HPP

class Car;

// Абстрактный класс состояния машины
class CarState {
public:
    virtual ~CarState() = default;

    // Обрабатывает ввод (нажатие/отпускание клавиши)
    virtual void handleInput(Car& car, int key, int action) = 0;

    // Обновляет состояние машины
    virtual void update(Car& car, float deltaTime) = 0;
};

#endif // CAR_STATE_HPP
