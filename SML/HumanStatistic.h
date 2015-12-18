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
	friend class GlobalPopulation;
	friend class Human;
	friend class Engine;
	//Postawowe informacje o postaci
	string surename, lastname, gender;
	int age, id;
	Text Surename, Lastname, Gender, Age, ID;

	//Statystyki
	int hp, inteligence, strength;
	RectangleShape background;
	HumanStatistic(string="Aga",string="Nowak",string="Kobieta",int=18,int=0);

	bool visible;

	static sf::Font font;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};