#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TextureLoader.h"

class SingleObject : public sf::Drawable, sf::Transformable
{
	friend class Ground;
	friend class Engine;
	sf::Sprite sprite;
	sf::RectangleShape collider;
	TextureLoader textures;
	SingleObject(int = 0, int = 0, int = 0);
	void setPosition(int, int);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool isWalkable;
};


class Ground : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	TextureLoader textures;
	
	int width = 20;
	int height = 20;
	//SingleObject ** map;
public:
	Ground();
	~Ground();
};

