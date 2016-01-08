#include "HumanAI.h"
#include <iostream>

using namespace std;


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
			if (tmp != NULL) state = CuttingTree; //jezeli dotarl do drzewa, to wtedy 
			state = Anythingelse;
		}
	}
	else if (state == Anythingelse)
	{
		state = Nothing;
	}
	else if (state == Nothing)
	{
		Vector2f vec(rand() % 1000, rand() % 1200);
		thisOne->inStage = true;
		thisOne->goToPoint(vec);
		state = Walking;
	}
}