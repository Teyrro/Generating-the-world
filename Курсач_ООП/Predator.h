#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>
#include <string>


class Predator : public Animal {
	Behavior predat;
public:
	static std::string id_predator;
	Predator(float hunger = 0.5, float chance = 0.25) : Animal() {
		predat.hunger = hunger;
		predat.The_probability_of_breeding = chance;
	}
	virtual std::string_view get_id() {
		return id_predator;
	}
};


