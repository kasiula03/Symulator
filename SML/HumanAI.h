#pragma once
#include <SFML\Graphics.hpp>
#include "GlobalObjects.h"
#include "Human.h"
using namespace sf;


class HumanAI
{
	friend class Human;
	friend class Engine;
	Human * thisOne;
	HumanAI();
	~HumanAI();
	enum Status {Talking, CuttingTree, Foraging, Building, Walking, Anythingelse, Nothing};
	void MainCore();

	Node <SingleObject> * tmp;
	Status state;
	bool Created;
	
};