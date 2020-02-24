#include "AngryBall.h"
AngryBall::AngryBall()
{
	drag = false;
	phys_speed_scale = 10.f;
	phys_gravity = 9.8f * phys_speed_scale;
}

AngryBall::~AngryBall()
{

}

void AngryBall::handleInput(float dt)
{
	if (input->isMouseRDown() && !drag)
	{
		mouseStartPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		drag = true;
	}
	else if (drag)
	{
		appliedForce = sf::Vector2f(input->getMouseX(), input->getMouseY()) - mouseStartPos;
		if (!input->isMouseRDown()) drag = false;
	}
}

void AngryBall::update(float dt)
{
	if(!drag) pos = appliedForce * dt + 0.5f * sf::Vector2f(0, phys_gravity) * dt;
	appliedForce += sf::Vector2f(0, phys_gravity) * dt;
	setPosition(getPosition() + pos);
	if (getPosition().y >= window->getSize().y - getSize().y / 2)
	{
		if(appliedForce.y > 0) appliedForce.y *= -1.f;
		setPosition(getPosition().x, window->getSize().y - getSize().y / 2);
	}
	if (getPosition().x >= window->getSize().x - getSize().x / 2)
	{
		appliedForce.x *= -1.f;
		setPosition(window->getSize().x - getSize().x / 2, getPosition().y);
	}
	if (getPosition().y <= 0 + getSize().y / 2)
	{
		appliedForce.y *= -1.f;
		setPosition(getPosition().x, 0 + getSize().y / 2);
	}
	if (getPosition().x <= 0 + getSize().y / 2)
	{
		appliedForce.x *= -1.f;
		setPosition(0 + getSize().x / 2, getPosition().y);
	}
}