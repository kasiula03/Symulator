#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "HumanStatistic.h"
#include "TextureLoader.h"
#include "HumanAI.h"

using namespace std;

class Human : public sf::Drawable, sf::Transformable, HumanAI
{
public:
	friend class Engine;
	friend class HumanStatistic;
	friend class GlobalPopulation;
	Human(string,string,string,int);
	Human();
	~Human();

	enum Status { IDZ, STOJ, Forward, Back};
	sf::Vector2f getPosition();
	//Status getStatus();

	void update(sf::Vector2f);
	void setRotation(float,float);
	void stop();
	void idz();
	void goToPoint(sf::Vector2f);
	
	int ID;
protected:
	int klatka_animacji;

private:
	static TextureLoader allTextures;
	sf::Sprite sprite;
	sf::RectangleShape EyesShot; //pole widzenia
	sf::RectangleShape HumanColision; //kolizja
	HumanStatistic stats;
	
	sf::RectangleShape du;
	Status status;
	Status direction;
	int direc;

	static float speed;
	size_t frame;
	float vx, vy;

	bool inStage;
	bool rotated;
	bool visibleStat;
	sf::Vector2f targetToGo; //Cel

	sf::Clock anim_clock;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

