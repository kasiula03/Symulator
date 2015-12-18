#include "GlobalObjects.h"
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace sf;

string temp;

void GlobalClock::SetSingleText(Text & tekst, string strText, float x, float y)
{
	tekst.setString(strText);
	tekst.setFont(font);
	tekst.setStyle(Text::Bold);
	tekst.setPosition(x, y);
}

void GlobalClock::SetTexts() //Ustawienie czasu (i opcji jego przyspieszenia) w prawym gornym rogu
{
	SetSingleText(textTime, "00:00:00", 1050, 20);

	SetSingleText(Faster, " << ", 900, 20);

	SetSingleText(Fast, " < ", 950, 20);

	SetSingleText(NormalSpeed, " I ", 1000, 20);
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

void GlobalData::SetSingleText(Text & tekst, string strText, float x, float y)
{
	tekst.setString(strText);
	tekst.setFont(font);
	tekst.setStyle(Text::Bold);
	tekst.setPosition(x, y);
}

void GlobalData::SetTexts()
{
	SetSingleText(Day, "Day " + to_string(day), 20, 20);
	
	SetSingleText(Month, "Month " + to_string(month), 100 , 20);

	SetSingleText(Year, "Year " + to_string(year), 210, 20);

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
