#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
//#include "Ground.h"
//#include "Player.h"
using namespace std;
using namespace sf;

class Engine;

class GlobalClock : public sf::Drawable, sf::Transformable
{
	friend class Engine;
public:
	int hour, minutes;
	float seconds;
	long long int timeSpeed;
	GlobalClock();
	~GlobalClock();
	bool UpdateTime();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	Font font;
	Text textTime;
	Text Fast,Faster, NormalSpeed;
	void SetTexts();
};

class GlobalData : public sf::Drawable, sf::Transformable
{
	friend class Engine;
public:
	int day, month, year;
	GlobalData();
	~GlobalData();
	void UpdateData();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Font font;
	Text Day, Month, Year;
	void SetTexts();
};