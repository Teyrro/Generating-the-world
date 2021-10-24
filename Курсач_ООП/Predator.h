#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>

#include <string>

class Predator : public Animal {
	Behavior predat;
	bool exception;
public:
	static std::string id_predator;
	static std::string id_victim;
	Predator(float hunger = 0.5, float chance = 0.25) : Animal(), exception(false) {
		predat.hunger = hunger;
		predat.The_probability_of_breeding = chance;
	}

	virtual Behavior& get_behavior() {
		return predat;
	}

	virtual std::string get_id() {
		return id_predator;
	}

	virtual std::string get_id_victim() {
		return id_victim;
	}
};


