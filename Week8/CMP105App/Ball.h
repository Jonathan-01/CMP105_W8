#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball :
	public GameObject
{
public:
	Ball(sf::RenderWindow* hwnd);
	~Ball();

	void update(float dt) override;
	void collisionResponse(GameObject* Collider);

protected:
	float speed;
	float scale;
	short temp;
	bool collided;
	sf::Vector2f pointA;
	sf::Vector2f pointB;
	sf::Vector2f direction;
	sf::RenderWindow* window;
};

