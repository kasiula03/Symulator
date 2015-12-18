#include "GlobalObjects.h"
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace sf;

string temp;


void GlobalClock::SetTexts() //Ustawienie czasu (i opcji jego przyspieszenia) w prawym gornym rogu
{
	textTime.setString("00:00:00");
	textTime.setFont(font);
	textTime.setStyle(Text::Bold);
	textTime.setPosition(1366 - textTime.getGlobalBounds().width * 3, 20);

	Faster.setString(" <<");
	Faster.setFont(font);
	Faster.setStyle(Text::Bold);
	Faster.setPosition(1366 - textTime.getGlobalBounds().width * 5, 20);

	Fast.setString(" <");
	Fast.setFont(font);
	Fast.setStyle(Text::Bold);
	Fast.setPosition(1366 - textTime.getGlobalBounds().width * 4.5, 20);

	NormalSpeed.setString(" I");
	NormalSpeed.setFont(font);
	NormalSpeed.setStyle(Text::Bold);
	NormalSpeed.setPosition(1366 - textTime.getGlobalBounds().width * 4, 20);

}

GlobalClock::GlobalClock()
{
	hour = 0;
	minutes = 0;
	seconds = 0;
	timeSpeed = 1;
	if (!font.loadFromFile("data/Mecha.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		return;
	}
	
	SetTexts();
}
GlobalClock::~GlobalClock()
{
	
}
bool GlobalClock::UpdateTime() // Mechanizm zegara
{
	seconds += (0.001 * timeSpeed);
	if (seconds > 60)
	{
		minutes++;
		seconds = 0;
	}
	if (minutes > 60)
	{
		hour++;
		minutes = 0;
	}
	if (hour > 23)
	{
		hour = 0;
		return true;
	}
	temp = to_string(hour) + ":" + to_string(minutes) + ":" + to_string((int)seconds);
	textTime.setString(temp);
	return false;
}
void GlobalClock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(this->textTime);
	target.draw(this->Faster);
	target.draw(this->NormalSpeed);
	target.draw(this->Fast);
	
}

void GlobalData::SetTexts()
{
	Day.setString("Day " + to_string(day));
	Day.setFont(font);
	Day.setStyle(Text::Bold);
	Day.setPosition(0 + Day.getGlobalBounds().width, 20);
	//Day.setOrigin(Day.getPosition());

	Month.setString("Month " + to_string(month));
	Month.setFont(font);
	Month.setStyle(Text::Bold);
	Month.setPosition(0 + Month.getGlobalBounds().width * 1.75, 20);
	//Month.setOrigin(Month.getPosition());

	Year.setString("Year " + to_string(year));
	Year.setFont(font);
	Year.setStyle(Text::Bold);
	Year.setPosition(0 + Year.getGlobalBounds().width * 4, 20);
	//Year.setOrigin(Year.getPosition());

}

GlobalData::GlobalData()
{
	if (!font.loadFromFile("data/Mecha.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		return;
	}
	day = 1;
	month = 1;
	year = 1;
	SetTexts();
}

GlobalData::~GlobalData()
{

}
void GlobalData::UpdateData()
{
	day++;
	if (day > 30)
	{
		month++;
		day = 1;
		Month.setString("Month " + to_string(month));
	}
	if (month > 12)
	{
		year++;
		month = 1;
		Year.setString("Year " + to_string(year));
	}
	Day.setString("Day " + to_string(day));
	
}
void GlobalData::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(this->Day);
	target.draw(this->Month);
	target.draw(this->Year);

}

listOfNames::listOfNames()
{
	cout << "Adres: " << &*this << endl;
}
