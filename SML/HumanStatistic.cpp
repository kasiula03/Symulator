#include "HumanStatistic.h"
#include <iostream>
#include "Engine.h"
using namespace std;
using namespace sf;

sf::Font HumanStatistic::font;

HumanStatistic::HumanStatistic(string _name, string _lname, string _gender, int _age,int _id)
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
	this->id = _id;
	this->visible = false;
	
	//background.setSize(Vector2f(80, 120));
	
	
	Surename.setString(surename.c_str());
	Surename.setStyle(Text::Bold);
	Surename.setFont(font);
	Surename.setPosition(10,10);
	Surename.setCharacterSize(20);
	
	Lastname.setString(lastname.c_str());
	Lastname.setStyle(Text::Bold);
	Lastname.setFont(font);
	Lastname.setPosition(20, 20);
	Lastname.setCharacterSize(20);

	Gender.setString(gender.c_str());
	Gender.setStyle(Text::Bold);
	Gender.setFont(font);
	Gender.setPosition(30, 30);
	Gender.setCharacterSize(20);

	Age.setString(to_string(age));
	Age.setStyle(Text::Bold);
	Age.setFont(font);
	Age.setPosition(30, 10);
	Age.setCharacterSize(20);

	ID.setString(to_string(age));
	ID.setStyle(Text::Bold);
	ID.setFont(font);
	ID.setPosition(30, 0);
	ID.setCharacterSize(20);

	if(lastname.length() > surename.length()) background.setSize(Vector2f(12 * lastname.length(),140));
	else  background.setSize(Vector2f(12 * surename.length(), 140));
	background.setFillColor(sf::Color(150, 75, 0, 255));
	background.setOrigin(32, 32);
	background.setPosition(1366 / 2, 768 / 2);
}


void HumanStatistic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(background);
	target.draw(Surename);
	target.draw(Lastname);
	target.draw(Gender);
	target.draw(Age);
	target.draw(ID);
	

}