#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Collider
{
public:
	Collider(RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collider other, float push);
	bool CheckCollision(Collider other);
	Vector2f GetPosition() { return body.getPosition(); }
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	RectangleShape& body;
};

