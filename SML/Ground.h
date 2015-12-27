#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "TextureLoader.h"

class Ground : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	TextureLoader textures;

public:
	Ground();
	~Ground();
};

