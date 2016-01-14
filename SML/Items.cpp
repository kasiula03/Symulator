#include "Items.h"
#include "Engine.h"
using namespace sf;


Trees::Trees(int x)
{
	this->x = x;
	int a = 0, b = 0;
	Node<SingleObject> * temp;
	for (int i = 0; i < x; i++)
	{
		trees.addNode(SingleObject(6,50,82)); //dodanie do listy drzew
	
	}
	temp = trees.head;
	while (temp)
	{
		temp->object.tag = "Tree";
		a = (rand() % 3600) - 500;
		b = (rand() % 2600) - 400;
		
		temp->object.collider.setScale(0.5, 0.1);
		//temp->object.collider.setSize(Vector2f(25, 41));
		temp->object.setPosition(a,b);
		temp->object.collider.setPosition(a + 15, b + 50);
		temp->object.isWalkable = false;
		temp = temp->next;
	}
}

void Trees::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	Node<SingleObject> * temp = trees.head;
	while (temp)
	{
		if (temp->which > 0) target.draw(temp->object);
		else break;
		temp = temp->next;
	}
	
}

Berries::Berries(int x)
{
	this->x = x;
	int a = 0, b = 0;
	Node<SingleObject> * temp;
	for (int i = 0; i < x; i++)
	{
		berries.addNode(SingleObject(10, 32, 38)); //dodanie do listy drzew

	}
	temp = berries.head;
	while (temp)
	{
		temp->object.tag = "Berry";
		a = (rand() % 3600) - 500;
		b = (rand() % 2600) - 400;

		temp->object.sprite.setScale(Vector2f(1.2, 1.2));
		temp->object.collider.setScale(Vector2f(1.2, 1.2));
		temp->object.setPosition(a, b);
		
		temp->object.isWalkable = false;
		temp = temp->next;
	}
}

void Berries::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	Node<SingleObject> * temp = berries.head;
	while (temp)
	{
		if (temp->which > 0) target.draw(temp->object);
		else break;
		temp = temp->next;
	}

}

void SomeItems::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	Node<SingleObject> * temp = someItems.head;
	while (temp)
	{
		if (temp->which > 0) target.draw(temp->object);
		else break;
		temp = temp->next;
	}
}