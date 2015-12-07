#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "HumanStatistic.h"

using namespace std;


class Human : public sf::Drawable, sf::Transformable
{
public:
	friend class Engine;
	friend class GlobalPopulation;
	Human(string="Aga",string="Nowak",string="Kobieta",int=18);
	~Human();

	enum Status { IDZ, STOJ, Forward, Back};
	sf::Vector2f getPosition();
	Status getStatus();

	void update();
	void setRotation(float,float);
	void stop();
	void idz();
	void goToPoint(sf::Vector2f);
	
protected:
	int klatka_animacji;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape EyesShot; //pole widzenia
	sf::RectangleShape HumanColision; //kolizja
	HumanStatistic stats;

	sf::RectangleShape du;
	Status status;
	Status direction;
	int direc;

	float speed;
	size_t frame;
	float vx, vy;

	bool inStage;
	bool rotated;
	bool visibleStat;
	sf::Vector2f targetToGo; //Cel

	sf::Clock anim_clock;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

