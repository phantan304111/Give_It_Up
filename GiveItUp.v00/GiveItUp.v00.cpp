// GiveItUp.v00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SceneManager.h"
#include <Windows.h>

//int Coin = 0;
//int Flag_level = 0;
//int Flag_skin = 0;
//int Music_volumn = 50;

int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "BiBle_JumP!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================
	SceneManager::GetInstance()->Init();

	Clock clock;
	Time elapsed;
	E e1 = NO;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					e1 = MOUSE_LEFT;
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
		
					e1 = MouseMoved;
			
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					e1 = MOUSE_LEFT_RELEASE;
				}
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
				{
					e1 = SPACE;
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		//std::cout << "dt: " << dt << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 
		SceneManager::GetInstance()->Update(dt,e1);

		// ================================ Draw ================================ 
		window.clear();
		SceneManager::GetInstance()->Render(window);

		window.display();

	//==================================================
	}
	

	return 0;
}

