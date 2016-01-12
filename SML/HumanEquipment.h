#pragma once
#include <string>

using namespace std;

class HumanEquipment
{
	friend class Human;
	friend class HumanAI;

	int woods;
	int saplings;
	int berries;

	HumanEquipment();
};