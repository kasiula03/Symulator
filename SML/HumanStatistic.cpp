#include "HumanStatistic.h"
#include <iostream>
#include "Engine.h"
using namespace std;
using namespace sf;

sf::Font HumanStatistic::font;

HumanStatistic::HumanStatistic(string _name, string _lname, string _gender, int _age)
{
	if (!font.loadFromFile("data//Mecha2.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		cout << "Nie udalo sie";
		return;
	}
	
	this->surename = _name;
	this->lastname = _lname;
	this->gender = _gender;
	this->age = _age;
	
	this->visible = false;
	
	
	Surename.setString(surename.c_str());
	Surename.setStyle(Text::Bold);
	Surename.setFont(font);
	Surename.setPosition(10,10);
	
	Lastname.setString(lastname.c_str());
	Lastname.setStyle(Text::Bold);
	Lastname.setFont(font);
	Lastname.setPosition(20, 20);

	Gender.setString(gender.c_str());
	Gender.setStyle(Text::Bold);
	Gender.setFont(font);
	Gender.setPosition(30, 30);

	Age.setString(to_string(age));
	Age.setStyle(Text::Bold);
	Age.setFont(font);
	Age.setPosition(40, 40);
}


void HumanStatistic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(Surename);
	target.draw(Lastname);
	target.draw(Gender);
	target.draw(Age);

}