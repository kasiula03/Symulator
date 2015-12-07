#include "HumanStatistic.h"
#include <iostream>

using namespace std;
using namespace sf;

HumanStatistic::HumanStatistic(string _name, string _lname, string _gender, int _age)
{
	if (!fontt.loadFromFile("data/Mecha2.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		cout << "Nie udalo sie";
		return;
	}
	//Font foncik = Engine::font;
	this->surename = _name;
	this->lastname = _lname;
	this->gender = _gender;
	this->age = _age;
	
	this->visible = false;
	
	
	Surename.setString(surename.c_str());
	Surename.setStyle(Text::Bold);
	//Surename.setFont(foncik);
	Surename.setPosition(10,10);
	
	//Surename.setString(surename.c_str());
	//Lastname.setString(lastname.c_str());
}


void HumanStatistic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	//target.draw(this->Surename);
	target.draw(Lastname);
	//target.draw(Gender);
	target.draw(Age);

}