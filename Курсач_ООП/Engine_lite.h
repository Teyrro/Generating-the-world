#pragma once
#include "Data.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"

#include <memory>
#include <list>
#include <iterator>

float remainder(float a);

struct Engine_lite {
	Plants* a;
	Herbivore* b;
	Predator* c;
	std::list<Animal*> array_all_classes;
	Data Map;
	int m_size;
	// Параметр отвечает за кол-во объектов
	Engine_lite(int size = 15) : Map(), m_size(size) {
		float a1[4]{ (m_size * 0.5f),  (m_size * 0.3f) , (m_size * 0.2f) };
		a1[3] = remainder(a1[0]) + remainder(a1[1]) + remainder(a1[2]);
		for (int i(0); i < a1[3]; i++) {
			
			switch (i % 3) {
				case 0: {
					a1[0]++;
					break;
				}
				case 1: {
					a1[1]++;
					break;
				}
				case 2: {
					a1[2]++;
					break;
				}
			}
		}

		for (int i(0); i < 4; i++) {
			a1[i] = static_cast<int>(a1[i]);
		}

		a = new Plants[a1[0]];
		b = new Herbivore[a1[1]];
		c = new Predator[a1[2]];
		for (int i(0), index(0); i < m_size; i++) {
			if (i < a1[0])
				array_all_classes.push_back(&a[i]);
			else if (i < (a1[0] + a1[1]))
				array_all_classes.push_back(&b[i - static_cast<int>(a1[0])]);
			else if (i >= (a1[0] + a1[1]))
				array_all_classes.push_back(&c[static_cast<int>(i - (a1[0] + a1[1]))]);
		}
		Map.creature_generation(array_all_classes);
	}	
};
