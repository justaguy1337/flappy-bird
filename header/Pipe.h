#pragma once
#include <SFML/Graphics.hpp>

class Pipe
{
public:
	Pipe(int y_pos);
	sf::Sprite sprite_up, sprite_down;
	static void loadTextures();
	void update(sf::Time& dt);
	double getRightBound();

private:
	static sf::Texture texture_up, texture_down;
	static int pipe_distance, move_speed;
};

