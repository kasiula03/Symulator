#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

class TextureLoader
{
public:
	TextureLoader();
	static Texture * textures;
	const Texture & operator[](int el);
};