
#include "Bird.h"
#include "Global.h"
Bird::Bird():
	gravity(15),
	flap_speed(400),
	animation_counter(0),
	texture_switch(0),
	should_fly(false)

{
	textures[0].loadFromFile("assets/birddown.png");
	textures[1].loadFromFile("assets/birdup.png");

	bird_sprite.setTexture(textures[0]);
	bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	resetBirdPosition();
}
void Bird::updateBird(sf::Time& dt)
{
	if (bird_sprite.getPosition().y + bird_sprite.getGlobalBounds().height < (WIN_HEIGHT * 3/4) && should_fly) {
		if (animation_counter == 5) {
			bird_sprite.setTexture(textures[texture_switch]);
			if (texture_switch) texture_switch = 0;
			else texture_switch = 1;

			animation_counter = 0;
		}
		animation_counter++;

		velocity_y += gravity * dt.asSeconds();
		bird_sprite.move(0, velocity_y);

		if(bird_sprite.getGlobalBounds().top < 0)
			bird_sprite.setPosition(bird_sprite.getPosition().x, 0);
	}
}

void Bird::flapBird(sf::Time& dt)
{
	velocity_y = flap_speed * dt.asSeconds() * -1;
}
double Bird::getRightBounds()
{
	return bird_sprite.getPosition().x + bird_sprite.getGlobalBounds().width;
}
void Bird::resetBirdPosition()
{
	bird_sprite.setPosition(100, WIN_HEIGHT / 2);
	velocity_y = 0.0;
}
 void Bird::setShouldFly(bool val)
 {
	 should_fly = val;
 }