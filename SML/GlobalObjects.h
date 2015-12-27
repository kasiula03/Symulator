#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include "Human.h"
#include <string>

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
	void SetSingleText(Text &, string, float, float);
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
	void SetSingleText(Text &, string, float, float);
};

class listOfNames
{
public:
	listOfNames();
	string namesWomen[11] = { "Sylwia","Klaudia","Monika","Agata","Pola","Gabriela","Justyna","Ola","Katherine","Monika","Urszula" };
	string SureNames[9] = { "Nowak","Kowal","Burzynski","Hanusiak","Bogusz","Jaworski","Typo","Sarmanczyk","Nacz" };
};

template<typename _typ> class Node
{
public:
	_typ object;
	//int which;
	Node * next;
};

template<typename type>class list
{
public:
	Node<type> * head;
	list() 
	{
		head = NULL;
	}
	
	void addNode(type & temp)
	{
		Node<type> * tempN = head;
		Node<type> * newNode = new Node<type>;
		newNode->next = NULL;
		newNode->object = temp;
		if (tempN == NULL) head = newNode;
		else
		{
			while (tempN->next) tempN = tempN->next;
			tempN->next = newNode;

		}
	}
};
