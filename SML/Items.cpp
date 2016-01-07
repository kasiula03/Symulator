#include "Items.h"

using namespace sf;

TextureLoader SingleObject::textures;

//Utworzenie pojedynczego obiektu
SingleObject::SingleObject(int which, int width, int height)
{
	sprite.setTexture(textures[which]);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	sprite.setPosition(0, 0);

	collider.setSize(Vector2f(width, height));

	collider.setFillColor(sf::Color(255, 232, 54, 120));
	//collider.setOrigin(32, 32);
	collider.setPosition(0, 0);
}
//Ustawienie pozycji
void SingleObject::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
	collider.setPosition(x, y);
	pos_x = x;
	pos_y = y;
}
void SingleObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
	//target.draw(collider);
}
Trees::Trees(int x)
{
	this->x = x;
	int a = 0, b = 0;
	Node<SingleObject> * temp;
	for (int i = 0; i < x; i++)
	{
		trees.addNode(SingleObject(6,50,82)); //dodanie do listy ludzi
	
	}
	temp = trees.head;
	while (temp)
	{
		temp->object.collider.setScale(0.5, 0.1);
		//temp->object.collider.setSize(Vector2f(25, 41));
		temp->object.setPosition(++a * 100, ++b * 100);
		temp->object.collider.setPosition((a * 100) + 15, (b * 100) + 50);
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
		target.draw(temp->object);
		temp = temp->next;
	}
}