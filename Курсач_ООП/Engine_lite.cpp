#include "Engine_lite.h"
float remainder(float a) {
	return (a - static_cast<int> (a));
}

Engine_lite::Engine_lite(int count_of_creature) : Map(), m_size(count_of_creature) {
	float percentage_of_the_number[4]{ (m_size * 0.5f),  (m_size * 0.3f) , (m_size * 0.2f) };
	percentage_of_the_number[3] = remainder(percentage_of_the_number[0]) + remainder(percentage_of_the_number[1]) + remainder(percentage_of_the_number[2]);
	for (int i(0); i < percentage_of_the_number[3]; i++) {

		switch (i % 3) {
		case 0: {
			percentage_of_the_number[0]++;
			break;
		}
		case 1: {
			percentage_of_the_number[1]++;
			break;
		}
		case 2: {
			percentage_of_the_number[2]++;
			break;
		}
		}
	}

	for (int i(0); i < 4; i++) {
		percentage_of_the_number[i] = static_cast<int>(percentage_of_the_number[i]);
	}

	a = new Plants[percentage_of_the_number[0]];
	b = new Herbivore[percentage_of_the_number[1]];
	c = new Predator[percentage_of_the_number[2]];

	for (int i(0); i < m_size; i++) {
		if (i < percentage_of_the_number[0])
			array_all_classes.push_back(&a[i]);
		else if (i <= (percentage_of_the_number[0] + percentage_of_the_number[1]))
			array_all_classes.push_back(&a[i - static_cast<int>(percentage_of_the_number[0])]);
		else if (i > (percentage_of_the_number[0] + percentage_of_the_number[1]))
			array_all_classes.push_back(&a[i - static_cast<int>(percentage_of_the_number[0] + percentage_of_the_number[1])]);
	}
	Map.creature_generation(array_all_classes);
}