#include "stdafx.h"
int Test()
{
	sf::RenderWindow window(sf::VideoMode(600, 600),"sfml");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				std::cout << " Mouse Pressed" << std::endl;
			}
		}
		window.clear();
		window.display();
	}
	return 1;
}