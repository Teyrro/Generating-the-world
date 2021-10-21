#pragma once
#include "Data.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"

#include <memory>
#include <vector>

class Engine_lite {
public:
	Data Map;
	std::vector<Animal> array_all_classes;
	Engine_lite() : array_all_classes(15), Map() {
		array_all_classes.resize(0);
		auto a = std::make_unique<Plants[]>(7);
		auto b = std::make_unique<Herbivore[]>(5);
		auto c = std::make_unique<Predator[]>(3);
		for (int i = 0; i < array_all_classes.size(); i++) {
			if (i < 9)
				array_all_classes.push_back(std::move(a[i]));
			else if (i < 14)
				array_all_classes.push_back(std::move(b[i]));
			else if (i > 14)
				array_all_classes.push_back(std::move(c[i]));
		}



	}
};

