#include "HumanAI.h"
#include <iostream>
#include "Engine.h"
using namespace std;

Engine * HumanAI::engine;

HumanAI::HumanAI()
{
	//cout << "Tworze AI" << endl;
	state = Nothing;
	tmp = NULL;
}

HumanAI::~HumanAI()
{
	cout << "Usuwam AI";
}

void HumanAI::MainCore()
{
	if (state == Talking)
	{

	}
	else if (state == CuttingTree)
	{
		thisOne->EQ->woods += 1;
		int ifSapling = rand() % 2;
		if (ifSapling == 1) thisOne->EQ->saplings += 1;
		if (thisOne->EQ->woods > 3)
		{
			state = Building;
			
		}
		else
		{
			state = Anythingelse;
		}
	}
	else if (state == Foraging)
	{

	}
	else if (state == Building)
	{
		if (engine->CheckCollision(thisOne) == false)
		{
			if (Campfire == false)
			{
				cout << "Tworze ognisko" << endl;
				Campfire = true;
				engine->items.someItems.addNode(SingleObject(7, 64, 64, thisOne->getPosition().x, thisOne->getPosition().y));
				PosCampfire.x = thisOne->getPosition().x;
				PosCampfire.y = thisOne->getPosition().y;
				thisOne->EQ->woods -= 4;
			}
			else if (Campfire && !House && thisOne->EQ->woods >= 15)
			{
				cout << "Tworze domek" << endl;
				House = true;
				engine->items.someItems.addNode(SingleObject(8, 76, 77, thisOne->getPosition().x, thisOne->getPosition().y));
				PosHouse.x = thisOne->getPosition().x;
				PosHouse.y = thisOne->getPosition().y;
				thisOne->EQ->woods -= 15;
			}
		}
		state = Anythingelse;
	}
	else if (state == Walking)
	{
		if (thisOne->stoped == true)
		{
			
			if (tmp != nullptr)
			{
				state = CuttingTree; //jezeli dotarl do drzewa, to wtedy 
			}
			else
			{
				state = Anythingelse;
			}
		}
	}
	else if (state == Anythingelse)
	{
		if (engine->CheckHumanEyesShot(thisOne)) //Szukanie celu (drzewa)
		{
			cout << "Znalazlem drzewo ";
			thisOne->inStage = true;
			thisOne->goToPoint(FoundTarget);
			state = Walking;
		}
		state = Nothing;
	}
	else if (state == Nothing)
	{
		Vector2f vec(rand() % 4000, rand() % 3000);
		thisOne->inStage = true;
		thisOne->goToPoint(vec);
		state = Walking;
	}
}