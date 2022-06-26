#include "block.h"

block::block(float pX, float pY, int weight) {
	this->shape.setPosition(pX, pY);								//Setting parameters of block 		
	this->shape.setSize( { this->blockWidth,this->blockHeight });
	this->shape.setFillColor(Color::Black);
	this->shape.setOrigin(this->blockWidth/2, this->blockHeight/2);
	this->mass = weight;



	std::string weighttext = std::to_string(weight);			// Setting parameters for text on the block
	this->text.setString(weighttext+"kg");
	if(!this->font.loadFromFile("Supertalls.ttf"))					// Loading font from file
	{
		exit(1);	//error...
	}

	this->text.setFont(font);
	this->text.setCharacterSize(50);
	this->text.setPosition(pX-10, pY+10);
	this->text.setOrigin((this->blockWidth / 2)-20, (this->blockHeight / 2));
}


void block::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->shape, state);								
	target.draw(this->text, state);
}



float block::bottom() {															// Defining edges of the block

	return this->shape.getPosition().y + this->shape.getSize().y/2;
}
float block::top() {

	return this->shape.getPosition().y - this->shape.getSize().y/2;
}
float block::left() {

	return this->shape.getPosition().x - this->shape.getSize().x / 2;
}
float block::right() {

	return this->shape.getPosition().x + this->shape.getSize().x / 2;
}




void block::update() {


	this->shape.move(this->velocityvector);	
	this->text.move(this->velocityvector);


	std::string weighttext = std::to_string(mass);									//Updating number displayed on the block
	this->text.setString(weighttext+"kg");
	if (!this->inair()) {																	//Adjusting mass(weight) of block (only on the ground)
		if (Keyboard::isKeyPressed(Keyboard::Key::W) and this->mass < maxkg)			
			this->mass++;
		else if (Keyboard::isKeyPressed(Keyboard::Key::S) and this->mass > minkg)
			this->mass--;
	}
}


bool block::inair() {
	if (shape.getPosition().y < ground)					//Defining if block is in air
		return true;
	else 
		return false;

}


void block::falling() {

	if (this->inair() and !Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		this->velocityvector.x = 0;
		this->velocityvector.y = speed;
		this->isfalling = true;
	}
	else if(isfalling and !this->inair()){
		this->velocityvector.x = 0;
		this->velocityvector.y = 0;
		isfalling = false;
	}
}


void block::antislide() {
	if (this->velocityvector.x and !this->velocityvector.y  and !Keyboard::isKeyPressed(Keyboard::Key::Space))
		this->velocityvector.x = 0;

}