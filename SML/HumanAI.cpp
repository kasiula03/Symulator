#include "HumanAI.h"
#include <iostream>

using namespace std;

HumanAI::HumanAI()
{
	//cout << "Tworze AI" << endl;
	state = Nothing;
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
			state = Anythingelse;
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
		//else thisOne->goToPoint(-vec);
		state = Walking;
	}
	//if (state == Anythingelse) cout << "Jest ";
	//cout << thisOne->stats.surename << " ";
	
}