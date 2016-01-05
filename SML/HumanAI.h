#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Human.h"
using namespace sf;

class HumanAI
{
	friend class Human;
	Human * thisOne;
	HumanAI();
	enum Status {};
	void DoSomething();
};