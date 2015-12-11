#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Ground.h"
#include "Player.h"
#include "GlobalObjects.h"
#include "Population.h"
using namespace std;
using namespace sf;


class Engine
{
public:
	Engine(sf::RenderWindow &win);
	~Engine(void);

	void runEngine(sf::RenderWindow &window);
	void UpdatePosition(int, int, float);
	
private:
	Human player;
	Ground ground;
	GlobalClock g_clock;
	GlobalData g_data;
	Font font;
	GlobalPopulation peoples;
	
};