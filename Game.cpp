#include "Game.h"
#include "Global.h"

Game::Game(sf::RenderWindow& window) : win(window),
is_space_pressed(false), 
run_game(true),
pipe_counter(71),
pipe_spawn_timer(70)
{
	win.setFramerateLimit(90);
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR,SCALE_FACTOR);
	bg_sprite.setPosition(0, -250);

	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);

	ground_sprite1.scale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.scale(SCALE_FACTOR, SCALE_FACTOR);

	ground_sprite1.setPosition(0, WIN_HEIGHT - ground_sprite1.getGlobalBounds().height);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, WIN_HEIGHT - ground_sprite1.getGlobalBounds().height);
	
	font.loadFromFile("assets/arcadeclassic.ttf");
	game_over_text.setFont(font);
	game_over_text.setCharacterSize(50);
	game_over_text.setFillColor(sf::Color::Black);
	game_over_text.setPosition(WIN_WIDTH / 2 - 230, WIN_HEIGHT / 2 - 100);
	game_over_text.setString("					Game Over!\nPress	R	to	Restart");
	Pipe::loadTextures();
}
void Game::doProcessing(sf::Time& dt)
{
	if(is_space_pressed) {
		moveGround(dt);

		if(pipe_counter> pipe_spawn_timer) {
			pipes.push_back(Pipe(dist(rd)));
			pipe_counter = 0;
		}
		pipe_counter++;

		for(int i=0;i<pipes.size();i++) {
			pipes[i].update(dt);
			if(pipes[i].getRightBound() < 0) {
				pipes.erase(pipes.begin() + i);
				i--;
			}
		}
		checkCollisions();
	}
	bird.updateBird(dt);
}
void Game::startGameLoop()
{
	while (win.isOpen()) {
		sf::Time dt = clock.restart();
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				win.close();
			if (event.type == sf::Event::KeyPressed && run_game) {
				if (event.key.code == sf::Keyboard::Space && !is_space_pressed) {
					is_space_pressed = true;
					bird.setShouldFly(true);
				}
				if(event.key.code == sf::Keyboard::Space && is_space_pressed) {
					bird.flapBird(dt);
				}
			}
			if(event.type == sf::Event::KeyPressed && !run_game) {
				if(event.key.code == sf::Keyboard::R) {
					restartGame();
				}
			}
		}
		doProcessing(dt);
		drawBackground();
		
		win.display();
	}
}

void Game::drawBackground()
{
	win.draw(bg_sprite);
	for (Pipe& pipe : pipes) {
		win.draw(pipe.sprite_down);
		win.draw(pipe.sprite_up);
	}
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
	win.draw(bird.bird_sprite);

	if(!run_game) {
		win.draw(game_over_text);
	}
}

void Game::moveGround(sf::Time& dt)
{
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0);
	if (ground_sprite1.getPosition().x + ground_sprite1.getGlobalBounds().width < 0)
		ground_sprite1.setPosition(ground_sprite2.getPosition().x + ground_sprite2.getGlobalBounds().width, ground_sprite1.getPosition().y);
	if (ground_sprite2.getPosition().x + ground_sprite2.getGlobalBounds().width < 0)
		ground_sprite2.setPosition(ground_sprite1.getPosition().x + ground_sprite1.getGlobalBounds().width, ground_sprite2.getPosition().y);
}

void Game::checkCollisions()
{
	if (!pipes.empty()) {
		const auto& pipe = pipes[0];
		const auto birdBounds = bird.bird_sprite.getGlobalBounds();
		double groundY = WIN_HEIGHT * 3 / 4;
		if (pipe.sprite_down.getGlobalBounds().intersects(birdBounds) ||
			pipe.sprite_up.getGlobalBounds().intersects(birdBounds) ||
			(birdBounds.top + birdBounds.height >= groundY))
		{
			is_game_over = true;
			run_game = false;
			is_space_pressed = false;
		}
	}
}


void Game ::restartGame()
{
	bird.resetBirdPosition();
	bird.setShouldFly(false);
	run_game = true;
	is_space_pressed = false;
	pipe_counter = 71;
	pipes.clear();
}