#include "Ball.h"

Ball::Ball(sf::RenderWindow* hwnd){
	speed = 5;
	scale = 100;

	window = hwnd;
}

Ball::~Ball(){

}

void Ball::update(float dt) {
	pointA = sf::Vector2f(getPosition());
	pointB = sf::Vector2f(input->getMouseX(), input->getMouseY());

	direction = pointB - pointA;
	direction = Vector::normalise(direction);
	if (!collided && temp > 288) {
		velocity = (direction * speed) * scale;
	}
	move(velocity * dt);
	collided = false;
	temp += 1;
}

void Ball::collisionResponse(GameObject* Collider) {
	velocity = -velocity;
	collided = true;
	temp = 0;
}