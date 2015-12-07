#include "Player.h"
#include <Windows.h>
#include <math.h>
#include <iostream>

using namespace sf;

#define M_PI 3.14159265358979323846

Human::Human(string _name,string _lname,string _gender,int _age) //Inicjalizacja postaci
{
	if (!texture.loadFromFile("data/images/princess.png"))
	{
		MessageBox(NULL, "Texture not found", "Error", NULL);
		return;
	}
	this->stats = HumanStatistic(_name, _lname, _gender, _age);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));
	sprite.setOrigin(32, 32);

	
	visibleStat = true;
	status = STOJ;
	direction = Back;
	frame = 0;
	speed = 0.5;
	rotated = false;
	inStage = false;
	direc = 0;
	sprite.setPosition(1366 / 2, 768 / 2);
	anim_clock.restart();

	HumanColision.setSize(Vector2f(60, 70));

	HumanColision.setFillColor(sf::Color(255, 232, 54, 120));
	HumanColision.setOrigin(32, 32);
	HumanColision.setPosition(1366/2, 768/2);
	
	EyesShot.setSize(Vector2f(250,600));
	EyesShot.setFillColor(sf::Color(255, 232, 54, 120));
	//EyesShot.setOrigin(125, (768/2) + 230 );
	EyesShot.setOrigin(EyesShot.getSize().x / 2, EyesShot.getSize().y + 10);
	EyesShot.setPosition(1366 / 2, 768 / 2);
	
}

Human::~Human()
{
}

Vector2f Human::getPosition()
{
	return HumanColision.getPosition();
}

void Human::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	//target.draw(EyesShot);
	target.draw(sprite);
	//target.draw(HumanColision);
	//if (visibleStat == true)
		//target.draw(stats);
}

void Human::update()
{
	if (inStage == true)
	{
		goToPoint(targetToGo);
	}
	if (anim_clock.getElapsedTime() > sf::seconds(0.09f))
	{

		if (status == STOJ) return;
		if (frame < 8)
			frame++;
		else
			frame = 0;
		if(direction == Forward) sprite.setTextureRect(IntRect(frame * 64, 128, 64, 64));
		else if (direction == Back) sprite.setTextureRect(IntRect(frame * 64, 0, 64, 64));
		anim_clock.restart();
	}

}

void Human::setRotation(float angle,float angleEye)
{
	
	sprite.setRotation(angle);
	HumanColision.setRotation(angle);
	EyesShot.setRotation(angleEye);

}

void Human::stop()
{
	status = STOJ;
	frame = 0;
}

void Human::idz()
{
	status = IDZ;

	float angle = sprite.getRotation();

	vx = sin((angle * M_PI) / 180.0f);
	vy = cos((angle * M_PI) / 180.0f);

	if (direction == Back) vy *= -1;
	else if (direction == Forward) vx *= -1;
	

	HumanColision.move(speed * vx / 5, speed * vy / 5);
	EyesShot.move(speed * vx / 5, speed * vy / 5);
	sprite.setPosition(HumanColision.getPosition());


}

void Human::goToPoint(Vector2f Point)
{
	//cout << "tak";
	float distx, disty;
	float temp;
	inStage = true;
	targetToGo = Point;
	
	distx = Point.x - this->getPosition().x;
	
	disty = Point.y - this->getPosition().y;
	
	float distance = sqrt(pow(distx,2) + pow(disty,2));
	if (disty < 0) direction = Status::Back;
	else if (disty > 0) direction = Status::Forward;
	if (rotated == false)
	{
	
		float rotation = asin((Point.y - this->getPosition().y) / distance) * 180.0f / M_PI;

		//if (Point.x < this->getPosition().x) rotation = 360 - rotation;
			
		float dir = -atan2(Point.x - this->getPosition().x, Point.y - this->getPosition().y) * 180.0f / M_PI;
	
		if (direction == Back)
		{
			dir += 180;
			temp = dir;
		}
		else
		{
			temp = dir + 180;
		}
		setRotation(dir,temp);
		rotated = true;
	}

	if(inStage)	idz();


	if (disty <= 5 && distx <= 5 && disty > -1 && distx > -1)
	{
		//std::cout << "jest" << std::endl;
		stop();
		rotated = false;
		inStage = false;
	}

}
