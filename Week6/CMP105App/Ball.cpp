#include "Ball.h"
Ball::Ball()
{
	speed = 100.f;
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	sf::Vector2f direction = (p->getPosition() - getPosition());
	direction = Vector::normalise(direction);
	velocity = direction * speed;
	setPosition(getPosition() + velocity * dt);
	if (Vector::magnitude(p->getPosition() - getPosition()) < 10.f) setPosition(1000, 300);
}