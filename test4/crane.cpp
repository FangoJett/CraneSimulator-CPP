#include "crane.h"


crane::crane(float pX, float pY) {
	this->shape.setPosition(pX,pY);
	this->shape.setRadius(this->radius);
	this->shape.setFillColor(Color::Black);
	this->shape.setOrigin(this->radius, this->radius);


}


void crane::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->shape, state);
}

void crane::update() {

	this->shape.move(this->velocityvector);									
		
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) and this->top() > 150)	//Moving along  Y axis
		this->velocityvector.y = -velocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) and this->bottom() < windowY-150)
		this->velocityvector.y = velocity;
	else
		this->velocityvector.y = 0;

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) and this->right() < windowX-200 )	//Moving along  X axis
		this->velocityvector.x = velocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left) and this->left() > 350)
		this->velocityvector.x = -velocity;
	else
		this->velocityvector.x = 0;




}    



float crane::bottom() {												// Defining edges of the "hook"

	return this->shape.getPosition().y + this->shape.getRadius();				
}
float crane::top() {

	return this->shape.getPosition().y - this->shape.getRadius();
}

float crane::right() {

	return this->shape.getPosition().x + this->shape.getRadius();
}
float crane::left() {

	return this->shape.getPosition().x - this->shape.getRadius();
}

