#include "Level.h"
#include "Ball.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in) : ball1(hwnd), ball2(hwnd)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");

	ball1.setSize(sf::Vector2f(100, 100));
	ball1.setPosition(100, 100);
	ball1.setTexture(&ballTexture);
	ball1.setInput(input);

	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(window->getSize().x - 200, window->getSize().y - 200);
	ball2.setTexture(&ballTexture);
	ball2.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2)) 
	{
		ball1.collisionResponse(NULL);
		ball2.collisionResponse(NULL); 
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
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