#include "Data.h"
#include "Array.h"
#include "Animal.h"

#include <iostream>

#include <list>
#include <iterator>

#include <string>

unsigned int Data::period(1);

// Заполнение карты пустотой 
std::string Data::map[12][12]{};

// Генерация объектов на текстовой карте
void Data::creature_generation(std::list<Animal*>& object) {
	std::vector<int> index(object.size());
	nonRecRand(index, 100);

	auto it(object.begin());
	for (unsigned long i(0); i < index.size(); i++, it++) {
		(*it)->set_coord(index[i] / 10 + 1, index[i] % 10 + 1);
		map[(*it)->get_coord().y][(*it)->get_coord().x] = (*it)->get_id();
	}
		
}

// Вывод текстовой карты
std::ostream& operator << (std::ostream& output_map, Data data) {
	for (int i(0); i < data.m_size; i++) {
		for (int j(0); j < data.m_size; j++)
			output_map << data.map[i][j] << " ";
		output_map << "\n";
	}
	return output_map;
}

void Data::check_for_dead(std::list<Animal*>& animals) {
	for (auto it(animals.begin()); it != animals.end(); it++) {
		sf::Vector2i temp((*it)->get_coord());
		if ((*it)->get_id() != map[temp.y][temp.x])
			(*it)->set_is_dead(true);
	}
}

//Проверка и поедание объекта
// desired - жаждить(желать) объект
void Data::check_desiredObj_and_eating(Animal* animal, std::string desiredObj, int radius) {
	for (int i(-radius); i <= radius; i++)
		for (int j(-radius); j <= radius; j++) {
			sf::Vector2i temp((animal->get_coord().x + i), (animal->get_coord().y + j));
			if ((temp.x) / m_size == 0 and (temp.y) / m_size == 0)
				if (map[temp.y][temp.x] == desiredObj) {
					map[temp.y][temp.x] = map[animal->get_coord().y][animal->get_coord().x];
					map[animal->get_coord().y][animal->get_coord().x] = "0";
					animal->set_coord(animal->get_coord().x + i, animal->get_coord().y + j);
					(animal)->get_behavior().hunger += 0.2f;
					return;
				}
		}

}

// Случайное движение
// victim - жертва
void Data::randMove(Animal* animal, std::string victim, int radius) {

	sf::Vector2i offset;
	while (1) {
		offset.x = radius - rand() % (2 * radius + 1);
		offset.y = radius - rand() % (2 * radius + 1);
		if ((animal->get_coord().x + offset.x) / m_size == 0 and (animal->get_coord().y + offset.y) / m_size == 0) {
			sf::Vector2i temp((animal->get_coord().x + offset.x), (animal->get_coord().y + offset.y));
			if ((offset.x != 0 or offset.y != 0) and (map[temp.y][temp.x] == "0" or map[temp.y][temp.x] == victim)) {
				map[temp.y][temp.x] = map[animal->get_coord().y][animal->get_coord().x];
				map[animal->get_coord().y][animal->get_coord().x] = "0";
				*animal += offset;
				if (map[temp.y][temp.x] == victim) {
					(animal)->get_behavior().hunger += 0.2f;
					return;
				}
				animal->get_behavior().hunger -= 0.2f;
				return;
			}
		}
	}
}

void Data::deathForHunger(std::list<Animal*>& animals) {
	for (auto it(animals.begin()); it != animals.end(); it++) {
		if ((*it)->get_behavior().hunger <= 0) {
			(*it)->set_is_dead(true);
			map[(*it)->get_coord().y][(*it)->get_coord().x] = "0";
		}
			
	}
}


//void Data::sex(std::list<Animal*>& animals) {
//
//	auto it(animals.end());
//	for (it;  (*it)->get_id() == "2" or it != animals.begin(); it--) {
//		short int percent(1 / (*it)->get_behavior().The_probability_of_breeding), probability(rand() % percent);
//		if (probability == 0)
//
//	}
//}

// Графическое движение, ещё не пришло время
void Data::move(std::list<Animal*>& animals) {
	for (auto it(animals.begin()); it != animals.end(); it++) {
		if (!(*it)->Is_dead()) {
			if ((*it)->get_id() == "4") {

				if (period % (*it)->getMoveTime() == 0) {
					if ((*it)->get_behavior().hunger < 0.4) {
						check_desiredObj_and_eating((*it), (*it)->get_id_victim(), 2);
						continue;
					}
					randMove((*it), (*it)->get_id_victim(), 1);
					continue;
				}
				(*it)->setMoveTime(rand() % 3 + 1);
			}
			else if ((*it)->get_id() == "3") {
					if (period % (*it)->getMoveTime() == 0)
						randMove((*it), (*it)->get_id_victim(), 3);
				(*it)->setMoveTime(rand() % 3 + 1);
			}
		}
	}
}