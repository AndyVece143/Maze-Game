#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.h"
using namespace std;
using namespace sf;

class Box
{
public:
	Box(Vector2f position, Texture& texture);
	~Box();

	Vector2f GetPosition() { return body.getPosition(); }
	void Draw(RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	void Move(Vector2f position, float deltaTime);
	void Update(float deltaTime);
	void ChangeState(bool isPressed);
	bool ReturnState();

private:
	RectangleShape body;
	float speed;
	bool moving;
	bool onSwitch;
};

