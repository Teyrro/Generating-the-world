#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>

#include <string>

class Predator : public Animal {
	Behavior predat;
	bool m_exception;
	int m_moveTime;
public:
	static std::string id_predator;
	static std::string id_victim;
	Predator(float hunger = 1, float chance = 0.25) : Animal(), m_exception(false), m_moveTime(1) {
		predat.hunger = hunger;
		predat.The_probability_of_breeding = chance;
	}

	virtual int const& getMoveTime() { return m_moveTime; }
	virtual void setMoveTime(int setMoveTime) { m_moveTime = setMoveTime; }
	virtual Behavior& get_behavior() {
		return predat;
	}

	virtual Animal* init(sf::Vector2i a) {
		Predator* ptr = new Predator;
		ptr->m_coord = a;
		return ptr;
	}

	virtual std::string get_id() {
		return id_predator;
	}

	virtual std::string get_id_victim() {
		return id_victim;
	}

	virtual sf::Vector2i sex(std::string map[][12], std::list<Animal*>::iterator& it);
};