#include "Items.h"

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
		a = (rand() % 3800) - 300;
		b = (rand() % 3000) - 400;
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
		if(temp->which > 0) target.draw(temp->object);
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