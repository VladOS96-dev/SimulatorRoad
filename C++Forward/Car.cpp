// Car.cpp
#include "Car.hpp"
#include "CarStationaryState.hpp"

// Конструктор класса Car
Car::Car()
	: x(0.75f), y(-0.75f), maxSpeed(1), turning(false), angle(90), speed(0), acceleration(0.01f), turningSpeed(4), carDirection(STOP), collisionStrategy(nullptr), currentState(new CarStationaryState()) {}

// Обрабатывает ввод (нажатие/отпускание клавиши)
void Car::handleInput(int key, int action) {
	currentState->handleInput(*this, key, action);
}

// Устанавливает текущее состояние машины
void Car::setState(CarState* state) {
	delete currentState;
	currentState = state;
}

// Метод для отрисовки автомобиля
void Car::render() const {
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	// Преобразование относительных координат в пиксельные
	float carX = Utils::toPixelX(x);
	float carY = Utils::toPixelY(y);
	glTranslatef(carX, carY, 0.0f);
	glRotatef(getAngle(), 0.0f, 0.0f, 1.0f);

	float halfWidth = Utils::toRelativeX(60.0f);
	float halfHeight = Utils::toRelativeY(60.0f);

	glBegin(GL_QUADS);
	glVertex2f(-halfWidth, -halfHeight);
	glVertex2f(halfWidth, -halfHeight);
	glVertex2f(halfWidth, halfHeight);
	glVertex2f(-halfWidth, halfHeight);
	glEnd();
	glPopMatrix();
}


// Обновляет состояние машины
void Car::update(float deltaTime) {

	float oldY = y;
	currentState->update(*this, deltaTime);

	x += speed * cosf(angle * 3.1415926f / 180.0f) * deltaTime;
	y += speed * sinf(angle * 3.1415926f / 180.0f) * deltaTime;
	UpdateCarDirection(oldY);

	// Ограничение движения по экрану
	if (x < -2.0f) x = -2.0f;
	if (x > 2.0f) x = 2.0f;
	if (y < -1.2f) y = -1.2f;
	if (y > 1.2f) y = 1.2f;

	// Постепенное уменьшение скорости
	if (speed > 0.0f) {
		speed -= acceleration * deltaTime;
		if (speed < 0.0f) {
			speed = 0.0f;
		}
	}
	else if (speed < maxSpeed) {
		speed += acceleration * deltaTime;
		if (speed > 0.0f) {
			speed = 0.0f;
		}
	}
}

float Car::getX() const
{
	return x;
}

float Car::getY() const
{
	return y;
}

void Car::setX(float x)
{
	this->x = x;
}

void Car::setY(float y)
{
	this->y = y;
}

// Возвращает ускорение машины
float Car::getAcceleration()const {
	return acceleration;
}

// Возвращает угол поворота машины
float Car::getAngle() const {
	return angle;
}

// Увеличивает скорость машины
void Car::increaseSpeed() {
	speed += acceleration;
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
}

// Уменьшает скорость машины
void Car::decreaseSpeed() {
	speed -= acceleration;
	if (speed < 0) {
		speed = 0;
	}
}

// Возвращает текущую скорость машины
float Car::getSpeed() const {
	return speed;
}

// Устанавливает скорость машины
void Car::setSpeed(float speed) {
	this->speed = speed;
}

// Начинает поворот машины
void Car::startTurn() {
	turning = true;
}

// Устанавливает ускорение машины
void Car::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

// Останавливает поворот машины
void Car::stopTurn() {
	turning = false;
}

// Возвращает состояние поворота машины
bool Car::getTurning()const {
	return turning;
}

// Поворачивает машину влево
void Car::rotateLeft() {
	if (speed > 0) {
		angle += turningSpeed;
	}
}

// Поворачивает машину вправо
void Car::rotateRight() {
	if (speed > 0) {
		angle -= turningSpeed;
	}
}

void Car::inertiaMove()
{
	speed -= acceleration;
	if (speed < 0) {
		speed = 0;
	}
}

// Возвращает направление движения машины
CarMoveDirection Car::getCarDirection() const {
	return carDirection;
}

// Обновляет направление движения машины
void Car::UpdateCarDirection(float oldY) {
	float deltaY = y - oldY;
	if (deltaY > 0) {
		carDirection = UP;
	}
	else if (deltaY < 0) {
		carDirection = DOWN;
	}
	else {
		carDirection = STOP;
	}
}

// Устанавливает стратегию столкновения
void Car::setCollisionStrategy(CollisionStrategy* strategy) {
	collisionStrategy = strategy;
}

// Проверяет столкновение
bool Car::checkCollision() const {
	if (collisionStrategy) {
		return collisionStrategy->checkCollision(*this);
	}
	return false;
}
