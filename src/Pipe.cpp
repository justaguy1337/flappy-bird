#include "header/Pipe.h"
#include "header/Global.h"
Pipe::Pipe(int y_pos)
{
	sprite_down.setTexture(texture_down);
	sprite_up.setTexture(texture_up);

	sprite_down.setScale(SCALE_FACTOR, SCALE_FACTOR);
	sprite_up.setScale(SCALE_FACTOR, SCALE_FACTOR);

	sprite_up.setPosition(WIN_WIDTH, y_pos);
	sprite_down.setPosition(WIN_WIDTH, y_pos - pipe_distance - sprite_up.getGlobalBounds().height);
}
void Pipe::update(sf::Time &dt)
{
	sprite_down.move(move_speed * dt.asSeconds() * -1, 0);
	sprite_up.move(move_speed * dt.asSeconds() * -1, 0);
}
void Pipe::loadTextures()
{
	texture_down.loadFromFile("assets/pipedown.png");
	texture_up.loadFromFile("assets/pipeup.png");
}
double Pipe::getRightBound()
{
	return sprite_down.getGlobalBounds().left + sprite_down.getGlobalBounds().width;
}
sf::Texture Pipe::texture_up, Pipe::texture_down;
int Pipe::pipe_distance = 250, Pipe::move_speed = 430;