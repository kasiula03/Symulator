#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Ground.h"
#include "Human.h"
#include "GlobalObjects.h"
#include "Population.h"
#include "Items.h"
using namespace std;
using namespace sf;


class Engine
{
	friend class HumanAI;
	friend class Berries;
public:
	Engine(RenderWindow &win);
	~Engine(void);

	void runEngine(RenderWindow &window);
	void UpdatePosition(int, int, float);
	void destroyTree(int);
	
	TextureLoader textures;
	sf::Sprite shadow;

	bool Sun;

private:
	Ground ground;
	Trees trees;
	GlobalClock g_clock;
	GlobalData g_data;
	Font font;
	GlobalPopulation peoples;
	SomeItems items;
	Berries berries;
	void Display(RenderWindow &);
	void MoveCamera(RenderWindow &, View &);
	void CheckCollision(); //Ogolna kolizja
	bool CheckCollision(Human *); //Kolizja szczegolowa, jednego czlowieka
	bool CheckCollision(Node<SingleObject> *);
	bool CheckHumanEyesShot(Human *);
};