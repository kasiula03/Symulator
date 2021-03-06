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
	string ObjectsTag;

	static Engine * engine;

	Status state;
	bool Created;
	Vector2f FoundTarget;

	//Stworzone obiekty

	bool Campfire;
	bool House;

	//Pozycje stworzonych obiektow
	Vector2i PosCampfire;
	Vector2i PosHouse;
	
};