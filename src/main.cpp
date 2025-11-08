#include <SFML/Graphics.hpp>
#include "header/Global.h"
#include "header/Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Flappy Bird");
	Game game(window);
	game.startGameLoop();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}
	return 0;
}