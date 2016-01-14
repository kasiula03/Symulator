#include "Population.h"
#include <iostream>

int GlobalPopulation::amount;

GlobalPopulation::GlobalPopulation(int x)
{
	this->x = x;
	for (int i = 0; i < x; i++)
	{
		listOfPeople.addNode(Human()); //dodanie do listy ludzi
	}
	Node<Human> * temp = listOfPeople.head;
	while(temp)
	{
		amount++;
		temp->object.ID = amount;
		temp = temp->next;
	}

}
void GlobalPopulation::CreateHuman(Human & hum)
{
	listOfPeople.addNode(Human(hum));
	Node<Human> * temp = listOfPeople.head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->object.ID = ++amount;
	temp->object.goToPoint(Vector2f(1, 1));
}
void GlobalPopulation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	Node<Human> * temp = listOfPeople.head;
	while(temp) 
	{
		target.draw(temp->object);
		temp = temp->next;
	}
}
void GlobalPopulation::update(sf::Vector2f mysz)
{
	Node<Human> * temp = listOfPeople.head;
	while(temp)
	{
		temp->object.update(mysz);
		temp = temp->next;
	}
}