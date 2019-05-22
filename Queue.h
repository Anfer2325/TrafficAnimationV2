#include "Car.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Queue
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	Queue();
	~Queue();
	Texture* blueCarTexture;

	//ARRIBA - ABAJO
	float currentPosX1, currentPosY1;
	//ABAJO - ARRIBA
	float currentPosX2, currentPosY2;
	//IZQUIERDA - DERECHA
	float currentPosX3, currentPosY3;
	//DERECHA - IZQUIERDA
	float currentPosX4, currentPosY4;

	Car* first;
	Car* last;

	int getCounter();

	void cQueue(Car*);
	Car * cDequeue();
	void startMovement();
	vector<Car *> getDraws();
};

