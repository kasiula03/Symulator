#include "TextureLoader.h"

Texture * TextureLoader::textures;

TextureLoader::TextureLoader()
{
	textures = new Texture[10];
	textures[0].loadFromFile("data//images//princess.png");
	textures[1].loadFromFile("data//images//male1.png");
	textures[2].loadFromFile("data//images//ground.png");
	textures[3].loadFromFile("data//images//hole.png"); //dziura
	textures[4].loadFromFile("data//images//dirt2.png");
	textures[5].loadFromFile("data//images//mapa.png");
	textures[6].loadFromFile("data//images//tree1.png");
	textures[7].loadFromFile("data//images//campfire1.png");
}
const Texture & TextureLoader::operator[](int el)
{
	return textures[el];
}