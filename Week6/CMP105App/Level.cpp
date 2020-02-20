#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	playerTex.loadFromFile("gfx/Player.png");
	player.setInput(input);
	player.setWindow(window);
	player.setTexture(&playerTex);
	player.setSize(sf::Vector2f(128, 128));
	player.setOrigin(sf::Vector2f(player.getSize().x / 2, player.getSize().y / 2));
	player.setPosition(444, 0 + player.getSize().y);
	player.setVelocity(sf::Vector2f(200.f, 0));

	ballTex.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&ballTex);
	ball.setTarget(player.getPosition());
	//setSize() is MANDATORY or it wont display
	ball.setSize(sf::Vector2f(64.f,64.f));
	ball.setOrigin(sf::Vector2f(ball.getSize().x / 2, ball.getSize().y / 2));
	ball.setPosition(1000, 300);

	ball2.setTexture(&ballTex);
	ball2.setTarget(sf::Vector2f(input->getMouseX(), input->getMouseY()));
	//setSize() is MANDATORY or it wont display
	ball2.setSize(sf::Vector2f(64.f, 64.f));
	ball2.setOrigin(sf::Vector2f(ball.getSize().x / 2, ball.getSize().y / 2));
	ball2.setPosition(0, 300);
	ball2.allowAcceleration(true);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	ball.setTarget(player.getPosition());
	ball2.setTarget(sf::Vector2f(input->getMouseX(), input->getMouseY()));
	ball.update(dt);
	ball2.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball2);
	window->draw(ball);
	window->draw(player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}