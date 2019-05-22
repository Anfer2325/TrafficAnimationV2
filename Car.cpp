#include "Car.h"
#include <Windows.h>
#include <iostream>
using namespace std;
Car::Car()
{
	setCarBrand(NONE);
	setPeople(0);
}

//1 ABAJO - ARRIBA
//2 ARRIBA - ABAJO
//3 IZQUIERDA - DERECHA
// 4 DERECHA - IZQUIERDA
Car::Car(int movType) {
	setCarBrand(NONE);
	setPeople(0);
	this->movementType = movType;
}
Car::Car(int p, carBrand cb, string d)
{
	setCarBrand(cb);
	setPeople(p);
	this->driver = d;
}

void Car::setCarBrand(carBrand cb)
{
	this->cBrand = cb;
}

carBrand Car::getCarBrand()
{
	return this->cBrand;
}

void Car::setPeople(int p)
{
	this->cPeople = p;

}

int Car::getPeople()
{
	return this->cPeople;
}

string Car::getDriver()
{
	return this->driver;
}

Car::~Car()
{
}

void Car::move() {

	switch (movementType)
	{
	case 1:
	{
		Vector2f pos = this->getPosition();
		pos.y -= 5;
		this->setPosition(pos);
		cout << "hola2";
		Sleep(50);
		break;
	}
	
	case 2:
	{
		Vector2f pos = this->getPosition();
		pos.y += 5;
		this->setPosition(pos);
		cout << "hola2";
		Sleep(50);
		break;
	}

	case 3:
	{
		Vector2f pos = this->getPosition();
		pos.x += 5;
		this->setPosition(pos);
		cout << "hola2";
		Sleep(50);
		break;
	}
	case 4: {
		Vector2f pos = this->getPosition();
		pos.x -= 5;
		this->setPosition(pos);
		cout << "hola2";
		Sleep(50);
		break;
	}
	}

	
	
}
