#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include "Human.h"
#include <string>

using namespace std;
using namespace sf;

class Engine;
class Trees;

class SingleObject : public sf::Drawable, sf::Transformable
{
	friend class Engine;
	friend class Trees;
	sf::Sprite sprite;
	sf::RectangleShape collider;
	static TextureLoader textures;
public:

	float pos_x, pos_y;
	SingleObject(int = 0, int = 0, int = 0,int = 0, int = 0);
	void setPosition(int, int);

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool isWalkable;
};

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
	int which;
	Node * next;
};

template<typename type>class list
{
public:
	Node<type> * head;
	list() 
	{
		head = NULL;
		//which = 1;
	}
	
	void addNode(type & temp)
	{
		Node<type> * tempN = head;
		Node<type> * newNode = new Node<type>;
		newNode->next = NULL;
		newNode->object = temp;
		int which = 2;
		if (tempN == NULL)
		{
			head = newNode;
			head->which = 1;
		}
		else
		{
			while (tempN->next)
			{
				tempN = tempN->next;
				which++;
			}
			tempN->next = newNode;
			tempN->next->which = which;

		}
	}
	void deleteNode(int wh)
	{
		Node<type> * tempN = head;
		Node<type> * helper;
		if (tempN)
		{
			if (head->which == wh)
			{
				head = tempN->next;
				delete tempN;
			}
			else
			{
				while (tempN->next->which != wh)
				{
					tempN = tempN->next;
					if (tempN == nullptr) break;
				}

				if (tempN->next->next == NULL)
				{
					/*helper = tempN->next;
					tempN->next == NULL;
					delete helper;*/
					deleteLast();
					
				}
				else
				{
					helper = tempN->next;
					tempN->next = helper->next;
					delete helper;
				}
				
			}
		}
	}

	void deleteLast()
	{
		Node<type> * tempN = head;
		if (tempN)
		{
			if (tempN->next)
			{
				while (tempN->next->next) tempN = tempN->next;
				delete tempN->next;
				tempN->next = NULL;
			}
			else
			{
				delete tempN;
				head = NULL;
			}
		}
	}


};
