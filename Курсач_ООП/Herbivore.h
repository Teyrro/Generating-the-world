#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <string_view>

class Herbivore : public Animal{
	Behavior herbi;
public:
	static std::string id_herbivore;
	Herbivore(float hunger = 0.5, float chance = 0.25) : Animal() {
		herbi.hunger = hunger;
		herbi.The_probability_of_breeding = chance;
	}
	virtual std::string_view get_id() {
		return id_herbivore;
	}
};


