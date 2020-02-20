#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "Player.h"
class Ball : public GameObject
{
private:
	float speed;
	Player* p;

public:
	Ball();
	~Ball();
	void update(float dt) override;
	void setTarget(Player* pete) { p = pete; };
};

