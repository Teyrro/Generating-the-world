#pragma once
#include "Data.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"
#include "Array.h"
#include <SFML/Graphics.hpp>

#include <memory>

#include <string>
#include <string_view>

#include <list>
#include <iterator>

float remainder(float a);

struct Engine_lite {
	Plants* a;
	Herbivore* b;
	Predator* c;
	std::list<Animal*> array_all_classes;
	Data Map;
	int renderedMap[12][12];
	sf::Texture texture;
	sf::Sprite obj;
	// ???-?? ??????
	static int count_f;
	// ?????? ????????
	int obj_size{ 41 };
	void createMap(int map[][12]);

	int m_size;

	// ???????? ???????? ?? ???-?? ????????
	Engine_lite(int count_of_creature = 20) : Map(), m_size(count_of_creature) {
		
		texture.loadFromFile("Sprite.png");
		createMap(renderedMap);
		obj.setTexture(texture);
		float percentage_of_the_number[4]{ (m_size * 0.6f),  (m_size * 0.3f) , (m_size * 0.1f) };
		percentage_of_the_number[3] = remainder(percentage_of_the_number[0]) + remainder(percentage_of_the_number[1]) + remainder(percentage_of_the_number[2]);
		for (int i(0); i < percentage_of_the_number[3]; i++) {

			switch (i % 3) {
			case 0: {
				percentage_of_the_number[0]++;
				break;
			}
			case 1: {
				percentage_of_the_number[1]++;
				break;
			}
			case 2: {
				percentage_of_the_number[2]++;
				break;
			}
			}
		}

		for (int i(0); i < 4; i++) {
			percentage_of_the_number[i] = static_cast<int>(percentage_of_the_number[i]);
		}

		a = new Plants[percentage_of_the_number[0]];
		b = new Herbivore[percentage_of_the_number[1]];
		c = new Predator[percentage_of_the_number[2]];

		for (int i(0); i < m_size; i++) {
			if (i < percentage_of_the_number[0])
				array_all_classes.push_back(&a[i]);
			else if (i < (percentage_of_the_number[0] + percentage_of_the_number[1]))
				array_all_classes.push_back(&b[i - static_cast<int>(percentage_of_the_number[0])]);
			else if (i >= (percentage_of_the_number[0] + percentage_of_the_number[1]))
				array_all_classes.push_back(&c[i - static_cast<int>(percentage_of_the_number[0] + percentage_of_the_number[1])]);
		}
		Map.creature_generation(array_all_classes);
		Map.update(array_all_classes);
	}

public:
	void draw_location(sf::RenderWindow& window);
	void draw_obj(sf::RenderWindow& window);
};