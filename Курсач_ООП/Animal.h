#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Animal {
	sf::Vector2f m_coord;
	
public:
	static short count_of_creatures;
	Animal(float coord_x = 10, float coord_y = 10) : m_coord(coord_x, coord_y)  {
		count_of_creatures++;
	}

	// обязательно подключить библиотеку memory и использовать std::move()
	void set_coord(float&& x, float&& y) {
		m_coord.x = x;
		m_coord.y = y;
	}

	virtual std::string_view get_id() {
		return nullptr;
	}

	sf::Vector2f& get_coord() {
		return m_coord;
	}

	void my_draw();
};

struct Behavior {
	float hunger;
	float The_probability_of_breeding;
};
