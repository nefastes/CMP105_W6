#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "Player.h"
class Ball : public GameObject
{
private:
	float speed;
	sf::Vector2f target;
	bool isAccelerating;
	float acceleration;

public:
	Ball();
	~Ball();
	void update(float dt) override;
	void setTarget(sf::Vector2f t) { target = t; };
	void allowAcceleration(bool b) { isAccelerating = b; };
};

