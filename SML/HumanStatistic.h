#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Human;

class HumanStatistic : public sf::Drawable, sf::Transformable
{
	friend class Human;
	friend class Engine;
	
	string surename, lastname, gender;
	int age;
	Text Surename, Lastname, Gender, Age;
	RectangleShape background;
	HumanStatistic(string="Aga",string="Nowak",string="Kobieta",int=18);

	bool visible;

	static sf::Font font;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};