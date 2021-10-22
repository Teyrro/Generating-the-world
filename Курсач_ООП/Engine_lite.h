#pragma once
#include "Data.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"

#include <memory>
#include <vector>

struct Engine_lite {
	Plants* a = new Plants[7];
	Herbivore* b = new Herbivore[5];
	Predator* c = new Predator[3];
	Data Map;
	int size = 15;
	std::vector<Animal*> array_all_classes;
	Engine_lite() : array_all_classes(size), Map() {
		array_all_classes.resize(0);
		for (int i(0); i < size; i++) {
			if (i < 7)
				array_all_classes.push_back(&a[i]);
			else if (i < 12)
					array_all_classes.push_back(&b[i%5]);
			else if (i >= 12)
					array_all_classes.push_back(&c[i%3]);
		}
		Map.creature_generation(array_all_classes);
	}	
};

