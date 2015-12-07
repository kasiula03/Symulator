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
	player = Human();
	peoples = GlobalPopulation(5);
	runEngine(win);

}


Engine::~Engine(void)
{
	cout << "Destroy engine" << endl;
}

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
	float SpeedMoveCamera = 10;
	float viewY = 0;
	float viewX = 0;
	float mouseX, mouseY;
	float tempSpeed = player.speed;
	
	while (!menu)
	{
		Event event;
		//Vector2f mysz(Mouse::getPosition(window));
		Vector2i mouseWindow = Mouse::getPosition(window);
		Vector2f mysz = window.mapPixelToCoords(mouseWindow);
		View view1 = window.getDefaultView();
	
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
			{
				menu = true;
				
				cout << "elo";
				//player.tempRot = 0;
			}

			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
			{
				//player.targetToGo = mysz;
				//player.inStage = true;
				if(player.inStage == false) player.goToPoint(mysz);
				//for (int i = 0; i < peoples.x; i++)
					//peoples.peoples[i].goToPoint(mysz);
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					cout << "move" << endl;
					//player.idz();

				}
				if (Keyboard::isKeyPressed(Keyboard::D))
				{
					player.rotate(2);
					//player.idz();
				}
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					player.rotate(-2);
				}
			}

			else if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::W)
					player.stop();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)
				{
					viewY -= SpeedMoveCamera;
					view1.move(viewX, viewY);
					UpdatePosition(0, -1, SpeedMoveCamera);
					window.setView(view1);

				}
				if (event.key.code == Keyboard::Down)
				{
					viewY += SpeedMoveCamera;
					view1.move(viewX, viewY);
					UpdatePosition(0, 1, SpeedMoveCamera);
					window.setView(view1);


				}
				if (event.key.code == Keyboard::Left)
				{
					viewX -= SpeedMoveCamera;
					view1.move(viewX, viewY);
					UpdatePosition(-1, 0, SpeedMoveCamera);
					window.setView(view1);


				}
				if (event.key.code == Keyboard::Right)
				{
					viewX += SpeedMoveCamera;
					view1.move(viewX, viewY);
					UpdatePosition(1, 0, SpeedMoveCamera);
					window.setView(view1);
				}
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
		player.update(); //aktualizacja polozenia gracza
		peoples.update();

		window.clear();
		window.draw(ground);
		window.draw(player);
		window.draw(peoples);
		window.draw(g_clock);
		window.draw(g_data);
		window.display();
	}
}

