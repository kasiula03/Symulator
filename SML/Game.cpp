#include "Game.h"
#include <iostream>
RenderWindow window(VideoMode(1366, 768), "Test", Style::Default); //Inicjalizacja glownego okna

Game::Game() //Zaladowanie tekstur i wejscie do menu
{
	state = END;
	if (!font.loadFromFile("data/Mecha.ttf"))
	{
		MessageBox(NULL, "Fond not found", "ERROR", NULL);
		return;
	}
	state = MENU;
}

Game::~Game()
{

}

void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
			menu();
			break;
		case GameState::GAME:
			single();
			break;
		}

	}
}

void Game::menu()
{
	Text tittle("Symulator rozwoju cywilizacji", font, 70);
	tittle.setStyle(Text::Bold);

	tittle.setPosition(1366 / 2 - tittle.getGlobalBounds().width / 2, 20);
	float mouseX;
	float mouseY;
	const int ile = 2;
	Text tekst[ile];
	string str[] = { "Play","Exit" };

	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);
		tekst[i].setString(str[i]);
		tekst[i].setPosition(1366 / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);

	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition());
		Event event;
		window.setView(window.getDefaultView());
		mouseX = sf::Mouse::getPosition(window).x;
		mouseY = sf::Mouse::getPosition(window).y;
		FloatRect invRect = FloatRect(tekst[0].getPosition().x, tekst[0].getPosition().y, 40, 40);
		FloatRect cursor_box = FloatRect(mouseX, mouseY, 1, 1);
		while (window.pollEvent(event))
		{
			Vector2f pos(tekst[0].getGlobalBounds().left, tekst[0].getGlobalBounds().top);
			Vector2f size(tekst[0].getGlobalBounds().width, tekst[0].getGlobalBounds().height);
			FloatRect newRect(static_cast < Vector2f >(window.mapCoordsToPixel(pos)), static_cast < Vector2f >(window.mapCoordsToPixel(size)));
			
			if (event.type == Event::Closed || event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				state = END;

			else if (newRect.contains(static_cast < Vector2f >(Mouse::getPosition(window))) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				cout << "Wchodzimy" << endl;
				state = GAME;
			}
			
			else if (tekst[1].getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window)) && event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
		}
	
		for (int i = 0; i<ile; i++)
		{
			
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Cyan);
			else tekst[i].setColor(Color::White);
		}

		window.clear();
		window.draw(tittle);
		for (int i = 0; i < ile; i++)
			window.draw(tekst[i]);
		window.display();


	}
}

void Game::single() //Wejscie do gry
{
	Engine engine(window);
	
	//engine.runEngine(window);
	state = MENU;
}