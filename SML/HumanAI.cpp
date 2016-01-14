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
		thisOne->EQ->berries += 1;
		state = Anythingelse;
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
			
			if (tmp != NULL)
			{
				if(ObjectsTag == "Tree") state = CuttingTree; //jezeli dotarl do drzewa, to wtedy 
				else if (ObjectsTag == "Berry") state = Foraging;
			}
			else
			{
				state = Anythingelse;
			}
		}
	}
	else if (state == Anythingelse)
	{
		/*if (engine->CheckHumanEyesShot(thisOne)) //Szukanie celu (drzewa)
		{
			cout << "Znalazlem drzewo ";
			thisOne->inStage = true;
			thisOne->goToPoint(FoundTarget);
			state = Walking;
		}*/
		int chance = rand() % 10;
		if (chance == 0)
		{
			if (thisOne->EQ->saplings != 0)
			{
				cout << "Sadze! " << thisOne->getPosition().x << " " << thisOne->getPosition().y << endl;
				thisOne->EQ->saplings -= 1;
				engine->trees.trees.addNode(SingleObject(6, 50, 82));
				Node <SingleObject> * temp = engine->trees.trees.head;
				while (temp->next) temp = temp->next;
				temp->object.setPosition(thisOne->getPosition().x + 60, thisOne->getPosition().y + 60);
			}
		}
		if (House && (engine->g_clock.hour > 23 || engine->g_clock.hour < 6))
		{
			Vector2f vek(PosHouse.x, PosHouse.y);
			thisOne->inStage = true;
			thisOne->goToPoint(vek);
			state = Walking;
		}
		else
		{
			state = Nothing;
		}
	}
	else if (state == Nothing)
	{
		Vector2f vec(rand() % 4000, rand() % 3000);
		thisOne->inStage = true;
		thisOne->goToPoint(vec);
		state = Walking;
	}
}