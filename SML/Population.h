#pragma once

#include "Player.h"

class GlobalPopulation : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	int x;
	Human * peoples;
public:
	GlobalPopulation(int=0);
	void CreateHuman();
	void update();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};