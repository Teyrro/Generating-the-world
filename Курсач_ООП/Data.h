#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include "Predator.h"
#include "Plants.h"
#include "Array.h"

#include <iostream>

#include <list>
#include <iterator>
#include <string>

class Data {
	const short m_size = 12;
	static unsigned int period;
	void addAnimal(std::list<Animal*>::iterator &it, std::list<Animal*>& animals, std::string id);
protected:
	static std::string map[12][12];

public:
	// Создание текстовой карты
	Data() {
		for (int i(0); i < m_size; i++) {
			if (i > 0 and i < 11)
				for (int j(1); j < 11; j++) {
					map[i][j] = "0";
				}
			else
				for (int j(0); j < m_size; j++) {
					map[i][j] = "1";
					map[j][i] = "1";
				}
		}
	}

	// Генерация объектов на текстовой карте
	void creature_generation(std::list<Animal*>& object);

	// Проверка съеденных животных
	void check_for_dead(std::list<Animal*>& animals);

	//Проверка и поедание объекта
	bool check_desiredObj_and_eating(Animal* animals, std::string desiredObj, int radius);

	// Случайное движение
	void randMove(Animal* &animals, std::string victim, int radius);

	// Графическое движение, ещё не пришло время
	void move(std::list<Animal*>& animals);

	// Проверка на смерть от голода
	void deathForHunger(std::list<Animal*>& animals);


	friend sf::Vector2i sex(Animal& animal);

	void probability(std::list<Animal*>& animals, int period);

	void update(std::list<Animal*>& animals) {

		try {
			
			check_for_dead(animals);
			move(animals);
			probability(animals, period);
			deathForHunger(animals);
			period = ++period;
		}
		catch (const char* excep) {
			std::cout << "Вызвано исключение: " << excep;
		}
		catch (...) {
			std::cout << "Вызвано исключение: NULL";
		}
	}

	// Вывод текстовой карты
	friend std::ostream& operator << (std::ostream& output_map, Data map);
};


