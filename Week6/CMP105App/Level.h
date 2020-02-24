#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Player.h"
#include "Ball.h"
#include "AngryBall.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	Player player;
	sf::Texture playerTex;

	Ball ball;
	sf::Texture ballTex;

	Ball ball2;

	AngryBall angryball;
};