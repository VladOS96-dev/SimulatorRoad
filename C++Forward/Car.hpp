#ifndef CAR_HPP
#define CAR_HPP

#include <math.h>
#include "CollisionStrategy.hpp"
#include "CarState.hpp"
#include"Utils.hpp"

class CollisionStrategy;

enum CarMoveDirection {
	UP,
	DOWN,
	STOP
};

class Car {
public:

	Car();
	// Обрабатывает ввод (нажатие/отпускание клавиши)
	void handleInput(int key, int action);

	// Обновляет состояние машины
	void update(float deltaTime);
	float getX()const;//возвращает х
	float getY()const;// возвращает y
	void setX(float x);//устанавливаем x
	void setY(float y);//устанавливаем y
	float getAcceleration()const;  // Возвращает ускорение машины
	float getAngle() const;   // Возвращает угол поворота машины
	void increaseSpeed();  // Увеличивает скорость машины
	void decreaseSpeed();  // Уменьшает скорость машины
	float getSpeed() const;  // Возвращает скорость машины
	void setSpeed(float speed);  // Устанавливает скорость машины
	void startTurn();  // Начинает поворот
	void setAcceleration(float acceleration);  // Устанавливает ускорение машины
	void stopTurn();  // Останавливает поворот
	bool getTurning()const;  // Возвращает состояние поворота машины
	void rotateLeft();  // Поворачивает машину влево
	void rotateRight();  // Поворачивает машину вправо
	void inertiaMove();//движение по инерции
	CarMoveDirection getCarDirection()const;  // Возвращает направление движения машины
	void UpdateCarDirection(float oldY);  // Обновляет направление движения машины
	void setCollisionStrategy(CollisionStrategy* strategy);  // Устанавливает стратегию столкновения
	bool checkCollision() const;  // Проверяет столкновение
	void setState(CarState* state);  // Устанавливает текущее состояние машины
	void render() const;// Метод для отрисовки автомобиля
private:
	float maxSpeed;  // Максимальная скорость
	bool turning;  // Состояние поворота
	float angle;  // Угол поворота
	float speed;  // Текущая скорость
	float acceleration;  // Текущее ускорение
	float turningSpeed;  // Скорость поворота
	CarMoveDirection carDirection;  // Направление движения
	CollisionStrategy* collisionStrategy;  // Стратегия столкновения
	CarState* currentState;  // Текущее состояние машины
	float x, y;  // Положение машины

};

#endif // CAR_HPP