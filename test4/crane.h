#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
using namespace sf;

class crane : public sf::Drawable
{
public:
	crane(float pX, float pY);
	~crane() = default;
	void update();
	float bottom();
	float top();
	float left();
	float right();
	Vector2f velocityvector{ 0,0 };
	CircleShape shape;

private:
	const float radius{ 10.0f };
	void draw(RenderTarget& target, RenderStates state) const override;
	const float velocity{ speed };
};

