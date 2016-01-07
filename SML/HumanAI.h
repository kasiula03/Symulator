#pragma once
#include <SFML\Graphics.hpp>
#include "Human.h"
using namespace sf;


class HumanAI
{
	friend class Human;
	Human * thisOne;
	HumanAI();
	~HumanAI();
	enum Status {Talking, CuttingTree, Foraging, Building, Walking, Anythingelse, Nothing};
	void MainCore();

	Status state;
	bool Created;
	
};