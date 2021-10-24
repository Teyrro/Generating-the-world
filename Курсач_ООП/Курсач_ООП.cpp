#include "Engine_lite.h"

#include "SFML/Graphics.hpp"

#include <iostream>


int main() {

	sf::Clock clock;
	//RenderWindow window(sf::VideoMode(640, 480), "Wild");


	Engine_lite a;
	while (true) {
		float time(clock.getElapsedTime().asMilliseconds());

		//std::cout << time << " ";

		if (time == 2000) {
			a.Map.update(a.array_all_classes);
			std::cout << a.Map << "\n";
			clock.restart();
		}
	}
}