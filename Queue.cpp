#include "Queue.h"
#include <thread>
Queue::Queue()
{
	this->first = nullptr;
	this->last = nullptr;
	this->counter = 0;
	this->currentPosX1 =460.f;
	this->currentPosY1 = 460.f;

	this->currentPosX2 = 375.f;
	this->currentPosY2 = 160.f;

	this->currentPosX3 = 270.f;
	this->currentPosY3 = 370.f;

	this->currentPosX4 = 570.f;
	this->currentPosY4 = 275.f;

	blueCarTexture = new Texture();
	if (!blueCarTexture->loadFromFile("redCar.png")) {
		
	};
}

Queue::~Queue()
{
}

int Queue::getCounter()
{
	return this->counter;
}

void Queue::increaseCounter()
{
	this->counter++;
}

void Queue::decreaseCounter()
{
	this->counter--;
}

void Queue::cQueue(Car* newCar)
{
	newCar->next = nullptr;

	if (getCounter() == 0)
	{
		this->first = newCar;
	
	}
	else
	{
		this->last->next = newCar;
	}
	
	newCar->setScale(0.13f, 0.13f);
	newCar->setTexture(*blueCarTexture);
	switch (newCar->movementType)
	{
	//Abajo - Arriba
	case 1: {
		newCar->rotate(180.f);
		newCar->setPosition(currentPosX1, currentPosY1);
		currentPosY1 += 70.f;
		break;
	}

	case 2: {
		newCar->rotate(0.f);
		newCar->setPosition(currentPosX2, currentPosY2);
		currentPosY2 -= 70.f;
		break;
	}
	case 3: {
		newCar->rotate(270.f);
		newCar->setPosition(currentPosX3, currentPosY3);
		currentPosX3 -= 70.f;
		break;
	}

	case 4: {
		newCar->rotate(90.f);
		newCar->setPosition(currentPosX4, currentPosY4);
		currentPosX4 += 70.f;
		break;
	}
	default:
		break;
	}
	

	this->last = newCar;
	
	increaseCounter();
}

Car * Queue::cDequeue()
{
	Car* tmp = this->first;

	if (tmp != nullptr)
	{
		if (this->first == this->last)
		{
			this->first = nullptr;
			this->last = nullptr;
		}
		else
			this->first = first->next;

		return tmp;
		decreaseCounter();
	}
	
	return NULL;
}

void Queue::startMovement() {
	for (int i = 0; i < 5; i++)
	{
		Car* tmp = this->cDequeue();
		if (tmp == NULL) {
			break;
		}
		else
		{
			thread* t1 = new thread(&Car::move,(*tmp));
			t1->detach();
			break;
		}
	}
}
