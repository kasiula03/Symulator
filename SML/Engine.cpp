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
	peoples = GlobalPopulation(6);
	trees = Trees(150);
	berries = Berries(50);
	peoples.listOfPeople.head->object.AI->engine = this;
	shadow.setTexture(textures[9]);
	shadow.setTextureRect(IntRect(0, 0, 4000, 3000));
	shadow.setPosition(-500, -300);
	Sun = false;
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

				}
				
			}
		}
		if (Keyboard::isKeyPressed)
		{
			MoveCamera(window, view1);

			//Przyspieszanie czasu
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
		if (g_clock.hour > 22 || g_clock.hour < 6)
			Sun = false;
		else
			Sun = true;

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
	window.draw(berries);
	window.draw(items);
	if (!Sun) window.draw(shadow);
	window.draw(g_clock);
	window.draw(g_data);

	window.display();
}

//Poruszanie kamera
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

//Ogolna kolizja
void Engine::CheckCollision()
{

	Node <SingleObject> * temp = this->trees.trees.head;

	while (temp)
	{

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
						tmpHum->object.AI->ObjectsTag = temp->object.tag;
						destroyTree(temp->which);
						temp = temp->next;

						tmpHum->object.stoped = true;
						tmpHum->object.stop();

						return;
					}
				}

				if (tmpHum->object.getPosition().x < -500 || tmpHum->object.getPosition().x > 3500 || tmpHum->object.getPosition().y < -400 || tmpHum->object.getPosition().y > 2600)
				{
					cout << "Granica! " << endl;
					tmpHum->object.stoped = true;
					tmpHum->object.stop();

					return;
				}

			}
			tmpHum = tmpHum->next;
		}
		temp = temp->next;

	}

	Node <SingleObject> * tempB = this->berries.berries.head;
	while (tempB)
	{
		FloatRect boxBerry(tempB->object.collider.getGlobalBounds());
		Node <Human> * tmpHum = peoples.listOfPeople.head;
		while (tmpHum)
		{
			if (tmpHum->object.status != Human::STOJ)
			{

				FloatRect box1(tmpHum->object.HumanColision.getGlobalBounds());
				if (box1.intersects(boxBerry))
				{
					if (tmpHum->object.inStage == true)
					{
						//cout << "Jagody" << endl;
						tmpHum->object.AI->tmp = tempB;
						tmpHum->object.AI->ObjectsTag = tempB->object.tag;
						tempB->object.sprite.setTextureRect(IntRect(32, 0, 32, 38));
						//destroyTree(temp->which);
						tempB = tempB->next;

						tmpHum->object.stoped = true;
						tmpHum->object.stop();

						return;

					}
				}
			}
			tmpHum = tmpHum->next;
		}
		tempB = tempB->next;
	}
}


//Sprawdzenie kolizji czlowieka
bool Engine::CheckCollision(Human * hum)
{
	Node <SingleObject> * temp = this->trees.trees.head;

	while (temp)
	{
		FloatRect boxTree(temp->object.collider.getGlobalBounds());

		FloatRect box1(hum->HumanColision.getGlobalBounds());
		if (box1.intersects(boxTree)) return true;
		else temp = temp->next;
	}
	Node <SingleObject> * tempI = this->items.someItems.head;

	while (temp)
	{
		FloatRect boxItems(tempI->object.collider.getGlobalBounds());

		FloatRect box1(hum->HumanColision.getGlobalBounds());
		if (box1.intersects(boxItems)) return true;
		else tempI = tempI->next;
	}
	return false;
}

//Sprawdzenie kolizji z polem widzenia czlowieka
bool Engine::CheckHumanEyesShot(Human * hum)
{
	Node <SingleObject> * temp = this->trees.trees.head;

	while (temp)
	{
		FloatRect boxTree(temp->object.collider.getGlobalBounds());

		FloatRect box1(hum->EyesShot.getGlobalBounds());
		if (box1.intersects(boxTree))
		{
			hum->AI->FoundTarget.x = temp->object.pos_x;
			hum->AI->FoundTarget.y = temp->object.pos_y;
			return true;
		}
		else temp = temp->next;
	}
	return false;
}

bool Engine::CheckCollision(Node<SingleObject> * tmp)
{
	Node <SingleObject> * temp = this->trees.trees.head;

	while (temp)
	{
		FloatRect boxTree(temp->object.collider.getGlobalBounds());

		FloatRect box1(tmp->object.collider.getGlobalBounds());
		if (box1.intersects(boxTree)) return true;
		else temp = temp->next;
	}
	Node <SingleObject> * tempI = this->berries.berries.head;
	while (tempI)
	{
		FloatRect boxTree(tempI->object.collider.getGlobalBounds());

		FloatRect box1(tmp->object.collider.getGlobalBounds());
		if (box1.intersects(boxTree)) return true;
		else tempI = tempI->next;
	}
	return false;

}

void Engine::destroyTree(int a)
{
	trees.trees.deleteNode(a);
}