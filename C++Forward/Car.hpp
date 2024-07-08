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
	// ������������ ���� (�������/���������� �������)
	void handleInput(int key, int action);

	// ��������� ��������� ������
	void update(float deltaTime);
	float getX()const;//���������� �
	float getY()const;// ���������� y
	void setX(float x);//������������� x
	void setY(float y);//������������� y
	float getAcceleration()const;  // ���������� ��������� ������
	float getAngle() const;   // ���������� ���� �������� ������
	void increaseSpeed();  // ����������� �������� ������
	void decreaseSpeed();  // ��������� �������� ������
	float getSpeed() const;  // ���������� �������� ������
	void setSpeed(float speed);  // ������������� �������� ������
	void startTurn();  // �������� �������
	void setAcceleration(float acceleration);  // ������������� ��������� ������
	void stopTurn();  // ������������� �������
	bool getTurning()const;  // ���������� ��������� �������� ������
	void rotateLeft();  // ������������ ������ �����
	void rotateRight();  // ������������ ������ ������
	void inertiaMove();//�������� �� �������
	CarMoveDirection getCarDirection()const;  // ���������� ����������� �������� ������
	void UpdateCarDirection(float oldY);  // ��������� ����������� �������� ������
	void setCollisionStrategy(CollisionStrategy* strategy);  // ������������� ��������� ������������
	bool checkCollision() const;  // ��������� ������������
	void setState(CarState* state);  // ������������� ������� ��������� ������
	void render() const;// ����� ��� ��������� ����������
private:
	float maxSpeed;  // ������������ ��������
	bool turning;  // ��������� ��������
	float angle;  // ���� ��������
	float speed;  // ������� ��������
	float acceleration;  // ������� ���������
	float turningSpeed;  // �������� ��������
	CarMoveDirection carDirection;  // ����������� ��������
	CollisionStrategy* collisionStrategy;  // ��������� ������������
	CarState* currentState;  // ������� ��������� ������
	float x, y;  // ��������� ������

};

#endif // CAR_HPP