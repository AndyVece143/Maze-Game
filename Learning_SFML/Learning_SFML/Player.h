#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Box.h"
using namespace std;
using namespace sf;

class Player
{
public:
	Player(Texture& texture);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	void Pulling(Box& box, float deltaTime);
	bool Finished();
	void MovePlayer(Vector2f position);


private:
	float x;
	float y;
	float speed;
	bool faceRight;
	bool faceUp;
	RectangleShape body;
	bool pullMode;

};

