#include "TextureLoader.h"

Texture * TextureLoader::textures;

TextureLoader::TextureLoader()
{
	textures = new Texture[2];
	textures[0].loadFromFile("data/images/princess.png");
	textures[1].loadFromFile("data/images/male.png");
}