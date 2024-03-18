
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "crane.h"
#include "block.h"

using namespace sf;

void picking(block& block,crane& crane);		// Allows crane to pick up block


int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;													//Setting antialiasing on maximum level
	block block(550, ground,100);
	crane crane(550, 300);
	RenderWindow window{ VideoMode{windowX, windowY},"CRANE",Style::Default, settings};		
	window.setFramerateLimit(60);
	Event event;

	while (true) {									//main loop 
		window.clear(Color::White);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}

		

		Texture texture;											//static part of crane
		Sprite cranemodel;
		if (!texture.loadFromFile("c21.jpg"))
			exit(2); //error...
		cranemodel.setTexture(texture);
		cranemodel.setPosition(-50, 37);
		window.draw(cranemodel);


		picking(block, crane);													//			Adjusting velocity vector of
		block.falling();														//			the blok
		crane.update();													//Updating postion of crane
		block.update();													//Updating mass and position of block
		block.antislide();

		RectangleShape line(sf::Vector2f(crane.top()-99, 1));				//"rope" that is attached to the "hook"(crane)
		line.setPosition(crane.shape.getPosition().x, 100);
		line.setFillColor(Color::Black);
		line.rotate(90);

		window.draw(line);
		window.draw(crane);
		window.draw(block);
		window.display();
		
	}
	return 0;
}




void picking(block& block, crane& crane) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) and crane.bottom() > block.top()
		and crane.left() > block.left() and crane.right() < block.right() and cranemaxkg>=block.mass)
	block.velocityvector = crane.velocityvector;
}

