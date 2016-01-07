#include "HumanAI.h"
#include <iostream>

using namespace std;

HumanAI::HumanAI()
{
	//cout << "Tworze AI" << endl;
}

HumanAI::~HumanAI()
{
	cout << "Usuwam AI";
}

void HumanAI::MainCore()
{
	Vector2f vec(rand() % 300, rand() % 400);
	thisOne->goToPoint(vec);
	
	//cout << thisOne->stats.surename << " ";
	
}