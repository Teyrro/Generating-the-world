#pragma once
#include "Animal.h"
#include <string>

class Data {
	const short size = 10;
	std::string map[10][10];
public:
	Data() {
		for (int i(0); i < size; i++) {
			if(i > 0 or i < 9)
				for (int j(1); j < 9; j++) {
					map[i][j] = "0";

				}
			else 
				for (int j(0); j < size; j++) {
					map[i][j] = "1";
					map[j][i] = "1";
				}
		}

	}

	void creature_generation(Animal& oblect) {

	}

	void move(Animal& oblect);
};

