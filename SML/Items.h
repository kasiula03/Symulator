#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TextureLoader.h"
#include "GlobalObjects.h"


class Trees : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	int x;
public:
	list<SingleObject> trees;
	Trees(int=0);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

class Berries : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	int x;
public:
	Engine * engine;
	list<SingleObject> berries;
	Berries(int = 0);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

class SomeItems : public sf::Drawable, sf::Transformable
{
public:
	list<SingleObject> someItems;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};