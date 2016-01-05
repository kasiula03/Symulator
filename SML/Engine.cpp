#include "Engine.h"
#include <iostream>
#include <Windows.h>
using namespace sf;
using namespace std;



Engine::Engine(sf::RenderWindow &win)
{
	
	if (!font.loadFromFile("data/Mecha.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		return;
	}
	player = Human("Ania","Kowal","Kobieta",25);
	peoples = GlobalPopulation(5);
	trees = Trees(8);
	runEngine(win);

}



Engine::~Engine(void)
{
	cout << "Destroy engine" << endl;
}

// Update pozycji tekstow daty i godziny
void Engine::UpdatePosition(int x, int y, float speed)
{
	g_data.Day.move(x * speed, y * speed);
	g_data.Month.move(x * speed, y * speed);
	g_data.Year.move(x * speed, y * speed);
	g_clock.textTime.move(x * speed, y * speed);
	g_clock.Fast.move(x * speed, y * speed);
	g_clock.Faster.move(x * speed, y * speed);
	g_clock.NormalSpeed.move(x * speed, y * speed);
}

void Engine::runEngine(sf::RenderWindow &window) //Glowna petla gry
{
	bool menu = false;
	float tempSpeed = player.speed;
	
	while (!menu)
	{
		Event event;
		Vector2i mouseWindow = Mouse::getPosition(window);
		Vector2f mysz = window.mapPixelToCoords(mouseWindow);
		View view1 = window.getDefaultView();
	
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape) menu = true; // Wyjscie do menu

			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) //poruszanie sie za pomoca myszki
			{
				if(player.inStage == false) player.goToPoint(mysz);
				//for (int i = 0; i < peoples.x; i++)
					//peoples.peoples[i].goToPoint(mysz);
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					peoples.CreateHuman();
				}
			}

			else if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::W)
					player.stop();
			}
			if (event.type == Event::KeyPressed)
			{
				MoveCamera(window,view1);

				if (event.key.code == Keyboard::Num1)
				{
					g_clock.timeSpeed = 1;
					player.speed = tempSpeed;
				}
				if (event.key.code == Keyboard::Num2)
				{
					player.speed = tempSpeed;
					g_clock.timeSpeed = 10;
					player.speed *= g_clock.timeSpeed;
				}
				if (event.key.code == Keyboard::Num3)
				{
					player.speed = tempSpeed;
					g_clock.timeSpeed = 50;
					player.speed *= g_clock.timeSpeed;
				}
			}
		}
		
		if (g_clock.UpdateTime())
		{
			g_data.UpdateData();
		}
		CheckCollision();
		player.update(mysz); //aktualizacja polozenia gracza(testowego)
		peoples.update(mysz); //aktualizacja wszystkich
		Display(window);
	}
}

void Engine::Display(RenderWindow & window)
{
	window.clear();
	window.draw(ground);
	window.draw(player);
	window.draw(peoples);
	window.draw(trees);
	window.draw(g_clock);
	window.draw(g_data);
	window.display();
}
void Engine::MoveCamera(RenderWindow & window,View & view1)
{
	static float viewX = 0;
	static float viewY = 0;
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		viewY -= 10;
		view1.move(viewX, viewY);
		UpdatePosition(0, -1, 10);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		viewY += 10;
		view1.move(viewX, viewY);
		UpdatePosition(0, 1, 10);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		viewX -= 10;
		view1.move(viewX, viewY);
		UpdatePosition(-1, 0, 10);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		viewX += 10;
		view1.move(viewX, viewY);
		UpdatePosition(1, 0, 10);
		window.setView(view1);
	}
}
void Engine::CheckCollision()
{
	//if (player.status == Human::STOJ) return;

	//pobranie aktualnej wartosci boxa
	
	int i = 0;
	Node<SingleObject> * temp = trees.trees.head;
	Node <Human> * tmpHum = peoples.listOfPeople.head;
	while (temp)
	{
		while(tmpHum)
		{
			if (tmpHum->object.status == Human::STOJ) return;
			FloatRect boxTree(temp->object.collider.getGlobalBounds());
			FloatRect box1(tmpHum->object.HumanColision.getGlobalBounds());
			if (tmpHum->object.HumanColision.getGlobalBounds().intersects(boxTree))
			{
				cout << "Kolizja" << endl;
				tmpHum->object.stoped = true;
				tmpHum->object.stop();
			}
		
			tmpHum = tmpHum->next;
		}

		temp = temp->next;
	}
}