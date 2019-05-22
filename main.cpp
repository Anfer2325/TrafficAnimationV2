#include <SFML/Graphics.hpp>

#include <iostream>
#include "Queue.h"
using namespace std;
using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(840, 630), "SFML works!");
	
	Queue cola1;
	
	Texture* texture = new Texture();
	if (!texture->loadFromFile("map.png")) {
		cout << "Hola";
	}

	Texture* blueCarTexture = new Texture();
	if (!blueCarTexture->loadFromFile("redCar.png")) {
		cout << "Error";
	};

	Sprite* map = new Sprite();
	map->setTexture(*texture);

	Car carro1(1);
	Car carro2(2);
	Car carro3(3);
	Car carro4(4);

	cola1.cQueue(&carro1);
	cola1.cQueue(&carro2);
	cola1.cQueue(&carro3);
	cola1.cQueue(&carro4);

	Car* car1 = cola1.cDequeue();
	Car* car2 = cola1.cDequeue();
	Car* car3 = cola1.cDequeue();
	Car* car4 = cola1.cDequeue();

	bool t1 = true;
	//blueCar->setScale(0.01f, 0.01f);
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(*map);
		window.draw(*car1);
		window.draw(*car2);
		window.draw(*car3);
		window.draw(*car4);

		window.display();
		car1->move();
		car2->move();
		car3->move();
		car4->move();

	}

	return 0;
}