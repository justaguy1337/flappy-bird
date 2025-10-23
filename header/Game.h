#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
#include <vector>
#include <random>
#include "Global.h"

class Game
{
public:
	Game(sf::RenderWindow& window);
	sf::RenderWindow& win;
	void startGameLoop();


private:
	sf::Texture bg_texture,ground_texture;
	sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
	sf::Clock clock;
	Bird bird;
	bool is_game_over, is_space_pressed,run_game, start_monitoring;
	const int move_speed = 270;
	void drawBackground();
	void moveGround(sf::Time& dt);
	void doProcessing(sf::Time &dt);
	void checkCollisions();
	void restartGame();
	void checkScore();
	int pipe_spawn_timer,pipe_counter,score;
	std::vector<Pipe> pipes;
	std::random_device rd;
	std::uniform_int_distribution<int> dist{ 150, WIN_HEIGHT - 250 };
	sf::Font font;
	sf::Text game_over_text, score_text, start_game;
	std::string score_string(int);
};

