#include "Population.h"
#include <iostream>

GlobalPopulation::GlobalPopulation(int x)
{
	this->x = x;

	Human nowy("d","d","d",5);
	for (int i = 0; i < x; i++)
		listOfPeople.addNode(nowy);
	sf::Vector2f vec;
	Node * temp = listOfPeople.head;
	int i = 0;
	while(temp)
	{
		if(i % 2 == 1)
			vec = sf::Vector2f(i * 100 , i * 10);
		else
			vec = sf::Vector2f(i * 100 , i * 50);
		std::cout << vec.x << vec.y << std::endl;
		temp->object.targetToGo = vec;
		temp->object.inStage = true;
		temp->object.goToPoint(vec);
		temp = temp->next;
		i++;
		//peoples[i].targetToGo = vec;
		//peoples[i].inStage = true;
		//peoples[i].goToPoint(vec);
		std::cout << "stworzyl sie" << std::endl;
	}

}
void GlobalPopulation::CreateHuman()
{
	
	
	
}
void GlobalPopulation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	Node * temp = listOfPeople.head;
	//target.draw(EyesShot);
	while(temp)
	{
		target.draw(temp->object);
		temp = temp->next;
		//cout << " rysowanie " << endl;
	}
	//target.draw(HumanColision);
}
void GlobalPopulation::update(sf::Vector2f mysz)
{
	Node * temp = listOfPeople.head;
	while(temp)
	{
		temp->object.update(mysz);
		temp = temp->next;
	}
}