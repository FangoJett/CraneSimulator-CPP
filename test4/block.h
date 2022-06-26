#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
using namespace sf;

class block : public sf::Drawable
{
public:
	block(float pX, float pY, int weight);
	~block() = default;
	int mass;
	bool isfalling;
	float bottom();
	float top();
	float left();
	float right();
	void update();
	bool inair();
	void falling();
	void antislide();
	Vector2f velocityvector{ 0,0 };
	


private:
	
	Text text;
	Font font;
	RectangleShape shape;
	const float blockWidth{ 150.0f };
	const float blockHeight{ 100.0f };
	const float velocity{ speed };
	

	void draw(RenderTarget& target, RenderStates state)const override;
};

