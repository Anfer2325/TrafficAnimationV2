#include <string>
#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

enum carBrand
{
	NONE = 0, TOYOTA, KIA, TESLA, NISSAN, LAMBORGHINI, HONDA, MITSUBISHI, MASERATI
};

class Car:public  sf::Sprite
{
private:
	int cPeople;
	carBrand cBrand;
	string driver;
	
	
	
public:
	int movementType;
	Car();
	Car(int);
	Car(int, carBrand, string);
	~Car();

	Car* next;

	void setPeople(int);
	int getPeople();

	void setCarBrand(carBrand);
	carBrand getCarBrand();

	string getDriver();

	void move();

	
};

