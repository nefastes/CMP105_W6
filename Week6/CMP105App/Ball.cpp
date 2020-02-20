#include "Ball.h"
Ball::Ball()
{
	speed = 100.f;
	isAccelerating = false;
	acceleration = 100.f;
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	sf::Vector2f direction = (target - getPosition());
	direction = Vector::normalise(direction);
	if (isAccelerating) velocity += direction * acceleration * dt;
	else velocity = direction * speed;
	setPosition(getPosition() + velocity * dt);
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(1000, 300);
		velocity = direction * speed;
	}
}