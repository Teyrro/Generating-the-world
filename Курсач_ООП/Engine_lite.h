#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"

#include <memory>

#include <string>
#include <string_view>

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
	Engine_lite(int count_of_creature = 15);
};