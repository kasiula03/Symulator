#include "HumanAI.h"
#include <iostream>

using namespace std;

HumanAI::HumanAI()
{
	//cout << "Tworze AI" << endl;
}

void HumanAI::DoSomething()
{
	Vector2f vec(rand() % 300, rand() % 400);
	thisOne->goToPoint(vec);
}