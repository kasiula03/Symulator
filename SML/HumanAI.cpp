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
		cout << "Tworze ognisko" << endl;
		Campfire = true;
		engine->items.someItems.addNode(SingleObject(7,32,32,thisOne->getPosition().x,thisOne->getPosition().y));
		thisOne->EQ->woods = 0;
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