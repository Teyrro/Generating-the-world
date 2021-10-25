#include "Engine_lite.h"

#include "SFML/Graphics.hpp"
#include<windows.h>
#include <iostream>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sf::Clock clock;
	//RenderWindow window(sf::VideoMode(640, 480), "Wild");


	Engine_lite a;
	std::cout << a.Map << "\n";
	int i = 0;
	while (true) {
		float time(clock.getElapsedTime().asMilliseconds());
		
		//std::cout << time << " ";

		if (time == 2000) {
			i++;
			std::cout<<"Период: "<<i<<"\n";
			a.Map.update(a.array_all_classes);
			std::cout << a.Map << "\n";
			clock.restart();
		}
	}
}