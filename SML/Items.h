#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TextureLoader.h"
#include "GlobalObjects.h"

class SingleObject : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	friend class Trees;
	sf::Sprite sprite;
	sf::RectangleShape collider;
	static TextureLoader textures;
	float pos_x, pos_y;
public:
	SingleObject(int = 0, int = 0, int = 0);
	void setPosition(int, int);
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool isWalkable;
};

class Trees : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	int x;
public:
	list<SingleObject> trees;
	Trees(int=0);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};