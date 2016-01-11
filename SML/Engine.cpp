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
	peoples = GlobalPopulation(3);
	trees = Trees(200);
	peoples.listOfPeople.head->object.AI->engine = this;
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

}

void Engine::runEngine(sf::RenderWindow &window) //Glowna petla gry
{
	bool menu = false;
	float tempSpeed = peoples.listOfPeople.head->object.speed;
	int i = 3;
	while (!menu)
	{
		Event event;
		Vector2i mouseWindow = Mouse::getPosition(window);
		Vector2f mysz = window.mapPixelToCoords(mouseWindow);
		View view1 = window.getDefaultView();

		while (window.pollEvent(event))
		{

			if (Keyboard::isKeyPressed(Keyboard::Escape)) menu = true; // Wyjscie do menu

			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					peoples.CreateHuman(Human("Katarzyna","Nalepka", "Kobieta",95));
					//Node<SingleObject> * temp = trees.trees.head;
					//trees.trees.addNode(SingleObject(6,50, 82,i++ * 100, i * 150));
					/*while (temp->next != nullptr)
					{
						temp = temp->next;
					}
					temp->object.setPosition(i++ * 100, i * 150);
					*/
					//peoples.listOfPeople.deleteNode(i++);
				}
				if (Keyboard::isKeyPressed(Keyboard::X))
				{
					Node<SingleObject> * temp = trees.trees.head;
					while (temp != NULL)
					{
						cout << temp->which << " ";
						cout << temp->object.pos_x << " " << temp->object.pos_y << endl;
						temp = temp->next;
					}
				}
			}
		}
		if (Keyboard::isKeyPressed)
		{
			MoveCamera(window, view1);

			if (Keyboard::isKeyPressed(Keyboard::Num1))
			{
				g_clock.timeSpeed = 1;
				peoples.listOfPeople.head->object.speed = tempSpeed;

			}
			if (Keyboard::isKeyPressed(Keyboard::Num2))
			{
				peoples.listOfPeople.head->object.speed = tempSpeed;
				g_clock.timeSpeed = 100;
				peoples.listOfPeople.head->object.speed *= g_clock.timeSpeed/10;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num3))
			{
				peoples.listOfPeople.head->object.speed = tempSpeed;
				g_clock.timeSpeed = 500;
				peoples.listOfPeople.head->object.speed *= g_clock.timeSpeed/10;
			}
		}


		if (g_clock.UpdateTime())
		{
			g_data.UpdateData();
		}

		peoples.update(mysz); //aktualizacja wszystkich
		CheckCollision();
		Display(window);
		
	}
}

void Engine::Display(RenderWindow & window)
{
	window.clear();
	window.draw(ground);
	window.draw(peoples);
	window.draw(trees);
	window.draw(items);
	window.draw(g_clock);
	window.draw(g_data);
	window.display();
}
void Engine::MoveCamera(RenderWindow & window, View & view1)
{
	static float viewX = 0;
	static float viewY = 0;
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		viewY -= 2;
		view1.move(viewX, viewY);
		UpdatePosition(0, -1, 2);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		viewY += 2;
		view1.move(viewX, viewY);
		UpdatePosition(0, 1, 2);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		viewX -= 2;
		view1.move(viewX, viewY);
		UpdatePosition(-1, 0, 2);
		window.setView(view1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		viewX += 2;
		view1.move(viewX, viewY);
		UpdatePosition(1, 0, 2);
		window.setView(view1);
	}
}
void Engine::CheckCollision()
{

	int i = 0;
	Node <SingleObject> * temp = this->trees.trees.head;

	while (temp)
	{
		int i = 0;
		if (temp == NULL)
		{
			break;
		}
		FloatRect boxTree(temp->object.collider.getGlobalBounds());
		Node <Human> * tmpHum = peoples.listOfPeople.head;
		while (tmpHum)
		{
			if (tmpHum->object.status != Human::STOJ)
			{
				
				FloatRect box1(tmpHum->object.HumanColision.getGlobalBounds());
				if (box1.intersects(boxTree))
				{
					if (tmpHum->object.inStage == true)
					{
						//cout << "Kolizja" << endl;
						tmpHum->object.AI->tmp = temp;
						destroyTree(temp->which);
						temp = temp->next;
				
						tmpHum->object.stoped = true;
						tmpHum->object.stop();
						
						return;
					
					}
				}
				
				//if(tmpHum->object.getPosition().x >)

			}
			tmpHum = tmpHum->next;
		}
		temp = temp->next;

	}
}

void Engine::destroyTree(int a)
{
	trees.trees.deleteNode(a);
}