#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"
#include "Array.h"

#include <iostream>
#include <string>

class Data {
	const short size = 12;
	std::string map[12][12];
public:
	Data() {
		for (int i(0); i < size; i++) {
			if(i > 0 and i < 11)
				for (int j(1); j < 11; j++) {
					map[i][j] = "0";
				}
			else 
				for (int j(0); j < size; j++) {
					map[i][j] = "1";
					map[j][i] = "1";
				}
		}
	}

	friend std::ostream& operator << (std::ostream& output_map, Data map);

	void creature_generation(std::vector<Animal*>& object) {
		std::vector<int> index(object.size());
		nonRecRand(index, 100);
		for (unsigned long i(0); i < index.size(); i++) {
			map[index[i] / 10 + 1][index[i] % 10 + 1] = object[i]->get_id();
		}
	}

	void move(Animal& oblect);
};