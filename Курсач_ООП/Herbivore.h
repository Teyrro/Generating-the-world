#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>

#include <string>

class Herbivore : public Animal {
	Behavior herbi;
	int m_moveTime;
public:
	static std::string id_herbivore;
	static std::string id_victim;
	Herbivore(float hunger = 1, float chance = 0.25) : Animal(), m_moveTime(1) {
		herbi.hunger = hunger;
		herbi.The_probability_of_breeding = chance;
	}

	virtual int const& getMoveTime() { return m_moveTime; }
	virtual void setMoveTime(int setMoveTime) { m_moveTime = setMoveTime; }

	virtual Behavior& get_behavior() {
		return herbi;
	}

	virtual Animal* init(sf::Vector2i a) {
		Herbivore* ptr = new Herbivore;
		ptr->m_coord = a;
		return ptr;
	}

	virtual std::string get_id() {
		return id_herbivore;
	}

	virtual std::string get_id_victim() {
		return id_victim;
	}
	virtual sf::Vector2i sex(std::string map[][12]);
};


