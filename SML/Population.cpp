#include "Population.h"
#include <iostream>



GlobalPopulation::GlobalPopulation(int x)
{
	this->x = x;

	Human nowy("d","d","d",5);
	for (int i = 0; i < x; i++)
		listOfPeople.addNode(nowy); //dodanie do listy ludzi
	sf::Vector2f vec;
	Node<Human> * temp = listOfPeople.head;
	int i = 0;
	while(temp)
	{
		if(i % 2 == 1)
			vec = sf::Vector2f(i * 100 , i * 10);
		else
			vec = sf::Vector2f(i * 100 , i * 50);
		//ustawienie pierwszego puntu docelowego
		temp->object.targetToGo = vec;
		temp->object.inStage = true;
		temp->object.goToPoint(vec);
		temp = temp->next;
		i++;
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