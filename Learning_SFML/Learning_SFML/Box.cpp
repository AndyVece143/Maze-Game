#include "Box.h"

Box::Box(Vector2f position, Texture& texture)
{
	body.setSize(Vector2f(100.0f, 100.0f));
	body.setPosition(position);
	body.setOrigin(body.getSize() / 2.0f);
	speed = 200;
	moving = false;
	onSwitch = false;
	body.setTexture(&texture);
}

Box::~Box()
{
}

void Box::Draw(RenderWindow& window)
{
	window.draw(body);
}

void Box::Move(Vector2f position, float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);

	Vector2f distance = body.getPosition() - position;
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	Vector2f normDistance(distance.x / length, distance.y / length);
	
	normDistance.x = -normDistance.x * 100 * deltaTime;
	normDistance.y = -normDistance.y * 100 * deltaTime;

	body.move(normDistance);
}

void Box::Update(float deltaTime)
{
}

void Box::ChangeState(bool isPressed)
{
	onSwitch = isPressed;
}

bool Box::ReturnState()
{
	return onSwitch;
}
