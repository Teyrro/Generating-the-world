#include "Engine_lite.h"

#include "SFML/Graphics.hpp"
#include<windows.h>
#include <iostream>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(492, 492), "Wild");


	Engine_lite a;

	std::cout << a.Map;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (time >= 10) {
			if (a.count_f == 120) {
				a.Map.update(a.array_all_classes);
				std::cout << a.Map;
				a.count_f = 1;
			}
			window.clear();
			a.draw_location(window);
			a.draw_obj(window);
			clock.restart();
			window.display();
		}
	
		
	}

}