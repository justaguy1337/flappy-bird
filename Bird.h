#pragma once
#include <SFML/Graphics.hpp>
class Bird
{
private:
	sf::Texture textures[2];
	const double gravity;
	const int flap_speed;
	double velocity_y;
	int animation_counter, texture_switch;
	bool should_fly;

public:
	sf::Sprite bird_sprite;
	Bird();
	void setShouldFly(bool val);
	void flapBird(sf::Time&dt);
	void resetBirdPosition();
	void updateBird(sf::Time& dt);
	double getRightBounds();
};

