#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Ground : public sf::Drawable, sf::Transformable
{
	sf::Sprite sprite;
	sf::Texture texture;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Ground();
	~Ground();
};