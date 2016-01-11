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
		cout << thisOne->EQ->woods << " ";
		state = Anythingelse;
	}
	else if (state == Foraging)
	{

	}
	else if (state == Building)
	{

	}
	else if (state == Walking)
	{
		if (thisOne->stoped == true)
		{
			
			if (tmp != nullptr)
			{
				state = CuttingTree; //jezeli dotarl do drzewa, to wtedy 

			}
			//state = Anythingelse;
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