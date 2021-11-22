#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>

#include <string>

class Plants : public Animal {
	Behavior plant;
	static int m_lifeTime;
	int m_lifePeriod;
public:
	static std::string id_plant;
	Plants(float hunger = 1, float chance = NULL) : Animal(), m_lifePeriod(1) {
		plant.hunger = hunger;
		plant.The_probability_of_breeding = chance;
	}

	virtual Behavior& get_behavior() {
		return plant;
	}
	virtual sf::Vector2i sex(std::string map[][12], std::list<Animal*>::iterator& it);
	virtual std::string get_id() {
		return id_plant;
	}

	int getLifeTime() {
		return m_lifeTime;
	}
	void setLifeTime(int lifeTime) {
		m_lifeTime = lifeTime;
	}
	virtual int get_lifePeriod() {
		return m_lifePeriod;
	}
	virtual void set_lifePeriod(int lifePeriod) {
		m_lifePeriod = lifePeriod;
	}
};


