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
	// �������� ��������� �����
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

	// ��������� �������� �� ��������� �����
	void creature_generation(std::list<Animal*>& object);

	// �������� ��������� ��������
	void check_for_dead(std::list<Animal*>& animals);

	//�������� � �������� �������
	bool check_desiredObj_and_eating(Animal* animals, std::string desiredObj, int radius);

	// ��������� ��������
	void randMove(Animal* &animals, std::string victim, int radius);

	// ����������� ��������, ��� �� ������ �����
	void move(std::list<Animal*>& animals);

	// �������� �� ������ �� ������
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
			std::cout << "������� ����������: " << excep;
		}
		catch (...) {
			std::cout << "������� ����������: NULL";
		}
	}

	// ����� ��������� �����
	friend std::ostream& operator << (std::ostream& output_map, Data map);
};


