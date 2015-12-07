#include "Ground.h"
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace sf;

Ground::Ground()
{

	if (!texture.loadFromFile("data/images/trawa.png"))
	{
		MessageBox(NULL, "Texture not found", "Error", NULL);
		return;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 600, 400));
	sprite.setOrigin(6, 6);
	sprite.setPosition(1366 /4 , 768 /4);
}
Ground::~Ground()
{

}
void Ground::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
}