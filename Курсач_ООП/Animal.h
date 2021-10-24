#pragma once
#include <SFML/Graphics.hpp>

#include <memory>

#include <string>

struct Behavior {
	float hunger;
	float The_probability_of_breeding;
	Behavior(float a = 0.4f, float b = 0.25f) : hunger(a), The_probability_of_breeding(b) {}
};

class Animal {
	sf::Vector2i m_coord;
	bool is_dead;
public:
	static short count_of_creatures;
	Animal(int coord_x = 10, int coord_y = 10) : m_coord(coord_x, coord_y), is_dead(false) {
		count_of_creatures++;
	}

	void set_is_dead(bool set);
	bool const& Is_dead();
	void set_coord(int&& x, int&& y);

	virtual std::string get_id() {
		throw NULL;
	}

	virtual std::string get_id_victim() {
		throw NULL;
	}

	//Обязательно Используйте исключения
	virtual Behavior& get_behavior() {
		throw " Вызов не переопределённой виртуальной фунции: behavior";
	}

	sf::Vector2i& get_coord() {
		return m_coord;
	}

	void my_draw();
};
