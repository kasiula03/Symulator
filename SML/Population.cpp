#include "Population.h"
#include <iostream>

GlobalPopulation::GlobalPopulation(int x)
{
	this->x = x;
	peoples = new Human[x]();
	sf::Vector2f vec;
	for (int i = 0; i < x; i++)
	{
		if(i % 2 == 1)
			vec = sf::Vector2f(i * 100 , i * 10);
		else
			vec = sf::Vector2f(i * 100 , i * 50);
		std::cout << vec.x << vec.y << std::endl;
		//peoples[i].targetToGo = vec;
		//peoples[i].inStage = true;
		peoples[i].goToPoint(vec);
		std::cout << "stworzyl sie" << std::endl;
	}

}
void GlobalPopulation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	//target.draw(EyesShot);
	for (int i = 0; i < this->x; i++)
	{
		target.draw(peoples[i]);
	}
	//target.draw(HumanColision);
}
void GlobalPopulation::update()
{
	for (int i = 0; i < this->x; i++)
		peoples[i].update();
}