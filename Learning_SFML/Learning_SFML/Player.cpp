#include "Player.h"

Player::Player(Texture& texture)
{
	body.setSize(Vector2f(100.0f, 100.0f));
	body.setPosition(200.0f, 200.0f);
	body.setOrigin(body.getSize() / 2.0f);

	//Make the speed 200 for final release!
	speed = 500;
	faceRight = true;
	faceUp = true;
	x = body.getPosition().x;
	y = body.getPosition().y;
	pullMode = false;
	body.setTexture(&texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//Movement
	Vector2f movement(0.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed * deltaTime;
		faceRight = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		movement.x += speed * deltaTime;
		faceRight = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.y -= speed * deltaTime;
		faceUp = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.y += speed * deltaTime;
		faceUp = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		pullMode = true;
		
	}

	if (Keyboard::isKeyPressed(Keyboard::P) == false)
	{
		pullMode = false;

	}

	//Make things simple
	x = body.getPosition().x;
	y = body.getPosition().y;

	body.move(movement);

	//cout << x << " " << y << endl;
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}

void Player::Pulling(Box& box, float deltaTime)
{
	if (pullMode == true)
	{
		box.Move(body.getPosition(), deltaTime);
	}
}

bool Player::Finished()
{
	if (x >= 1550)
	{
		return true;
	}

	return false;
}

void Player::MovePlayer(Vector2f position)
{
	body.setPosition(position);
}

