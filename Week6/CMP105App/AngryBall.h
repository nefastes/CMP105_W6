#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class AngryBall : public GameObject
{
private:
	//Variables to handle the drag of the mouse
	sf::Vector2f mouseStartPos;
	sf::Vector2f appliedForce;
	bool drag;

	//Variables for the ball itslef
	float phys_speed_scale;
	float phys_gravity;
	sf::Vector2f pos;

	//Window
	sf::RenderWindow* window;

public:
	AngryBall();
	~AngryBall();
	void handleInput(float dt) override;
	void update(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
};

