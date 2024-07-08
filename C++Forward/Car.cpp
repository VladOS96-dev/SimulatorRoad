// Car.cpp
#include "Car.hpp"
#include "CarStationaryState.hpp"

// ����������� ������ Car
Car::Car()
	: x(0.75f), y(-0.75f), maxSpeed(1), turning(false), angle(90), speed(0), acceleration(0.01f), turningSpeed(4), carDirection(STOP), collisionStrategy(nullptr), currentState(new CarStationaryState()) {}

// ������������ ���� (�������/���������� �������)
void Car::handleInput(int key, int action) {
	currentState->handleInput(*this, key, action);
}

// ������������� ������� ��������� ������
void Car::setState(CarState* state) {
	delete currentState;
	currentState = state;
}

// ����� ��� ��������� ����������
void Car::render() const {
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();

	// �������������� ������������� ��������� � ����������
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


// ��������� ��������� ������
void Car::update(float deltaTime) {

	float oldY = y;
	currentState->update(*this, deltaTime);

	x += speed * cosf(angle * 3.1415926f / 180.0f) * deltaTime;
	y += speed * sinf(angle * 3.1415926f / 180.0f) * deltaTime;
	UpdateCarDirection(oldY);

	// ����������� �������� �� ������
	if (x < -2.0f) x = -2.0f;
	if (x > 2.0f) x = 2.0f;
	if (y < -1.2f) y = -1.2f;
	if (y > 1.2f) y = 1.2f;

	// ����������� ���������� ��������
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

// ���������� ��������� ������
float Car::getAcceleration()const {
	return acceleration;
}

// ���������� ���� �������� ������
float Car::getAngle() const {
	return angle;
}

// ����������� �������� ������
void Car::increaseSpeed() {
	speed += acceleration;
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
}

// ��������� �������� ������
void Car::decreaseSpeed() {
	speed -= acceleration;
	if (speed < 0) {
		speed = 0;
	}
}

// ���������� ������� �������� ������
float Car::getSpeed() const {
	return speed;
}

// ������������� �������� ������
void Car::setSpeed(float speed) {
	this->speed = speed;
}

// �������� ������� ������
void Car::startTurn() {
	turning = true;
}

// ������������� ��������� ������
void Car::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

// ������������� ������� ������
void Car::stopTurn() {
	turning = false;
}

// ���������� ��������� �������� ������
bool Car::getTurning()const {
	return turning;
}

// ������������ ������ �����
void Car::rotateLeft() {
	if (speed > 0) {
		angle += turningSpeed;
	}
}

// ������������ ������ ������
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

// ���������� ����������� �������� ������
CarMoveDirection Car::getCarDirection() const {
	return carDirection;
}

// ��������� ����������� �������� ������
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

// ������������� ��������� ������������
void Car::setCollisionStrategy(CollisionStrategy* strategy) {
	collisionStrategy = strategy;
}

// ��������� ������������
bool Car::checkCollision() const {
	if (collisionStrategy) {
		return collisionStrategy->checkCollision(*this);
	}
	return false;
}
