#pragma once
#include "Animal.h"

#include <SFML/Graphics.hpp>
#include <string>

class Plants : public Animal {
	Behavior plant;
	
public:
	static std::string id_plant;
	Plants(float hunger = 1, float chance = NULL) : Animal() {
		plant.hunger = hunger;
		plant.The_probability_of_breeding = chance;
	}

	virtual std::string_view get_id() {
		return id_plant;
	}
};


