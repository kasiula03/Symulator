#include "Population.h"
#include <iostream>

int GlobalPopulation::amount;

GlobalPopulation::GlobalPopulation(int x)
{
	this->x = x;

	//Human nowy("d","d","d",5);
	for (int i = 0; i < x; i++)
	{
		listOfPeople.addNode(Human()); //dodanie do listy ludzi
	}
	Node<Human> * temp = listOfPeople.head;
	int i = 0;
	while(temp)
	{
		amount++;


		temp->object.ID = amount;

		temp = temp->next;
		i++;
		//cout << amount << endl;
	}

}
void GlobalPopulation::CreateHuman()
{
	listOfPeople.addNode(Human());
	Node<Human> * temp = listOfPeople.head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->object.ID = ++amount;
	cout << amount << endl;
	temp->object.goToPoint(Vector2f(1, 1));
}
void GlobalPopulation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	Node<Human> * temp = listOfPeople.head;
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
	Node<Human> * temp = listOfPeople.head;
	while(temp)
	{
		temp->object.update(mysz);
		temp = temp->next;
	}
}