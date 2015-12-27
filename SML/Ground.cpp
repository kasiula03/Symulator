#include "Ground.h"
#include <Windows.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace sf;
using namespace std;

Ground::Ground()
{
	
	/*map = new SingleObject*[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new SingleObject[height];
	}
	fstream plik;
	plik.open("data//map.txt", ios::in);
	if (!plik.good())
	{
		MessageBox(NULL, "Nie mozna zaladowac mapy", "ERROR", NULL);
		return;
	}
	cout << width << " " << height << endl;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int tmp = 0;
			plik >> tmp;
			
			if (tmp == 0)
			{
				map[x][y] = SingleObject(4, 100, 100);
				map[x][y].setPosition(x * 100, y * 100);
				map[x][y].isWalkable = false;
				
				
			}
			else
			{
				map[x][y] = SingleObject(2, 100, 100);
				map[x][y].setPosition(x * 100, y * 100);
				map[x][y].isWalkable = true;
			}
			//cout << map[x][y].getPosition().x << " " << map[x][y].getPosition().y << endl;
		}
	}*/
	sprite.setTexture(textures[5]);
	sprite.setTextureRect(IntRect(0, 0, 2000, 1500));
	sprite.setPosition(0, 0);
}
Ground::~Ground()
{

}
void Ground::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	/*for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			target.draw(map[i][j]);
		}
	}*/
	target.draw(sprite);
}

//Utworzenie pojedynczego obiektu
SingleObject::SingleObject(int which,int width,int height)
{
	sprite.setTexture(textures[which]);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	sprite.setPosition(0, 0);

	collider.setSize(Vector2f(width, height));

	collider.setFillColor(sf::Color(255, 232, 54, 120));
	//collider.setOrigin(32, 32);
	collider.setPosition(0,0);
}
//Ustawienie pozycji
void SingleObject::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
	collider.setPosition(x, y);
}
void SingleObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite);
	//target.draw(collider);
}