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
	
	string surename, lastname, gender;
	int age;
	Text Surename, Lastname, Gender, Age;
	HumanStatistic(string="Aga",string="Nowak",string="Kobieta",int=18);

	bool visible;

	Font fontt;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};