#include "Data.h"
#include "Array.h"
#include "Animal.h"

#include <iostream>

#include <list>
#include <iterator>
#include<windows.h>
#include <string>

unsigned int Data::period(1);

// Заполнение карты пустотой 
std::string Data::map[12][12]{};

std::string Data::location[12][12]{};

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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i(0); i < data.m_size; i++) {
		for (int j(0); j < data.m_size; j++) {
			
			if (data.map[i][j] == "1") SetConsoleTextAttribute(handle, 11);	//голубой
			if (data.map[i][j] == "2") SetConsoleTextAttribute(handle, 10);	//зеленый
			if (data.map[i][j] == "3") SetConsoleTextAttribute(handle, 14);	//желтый
			if (data.map[i][j] == "4") SetConsoleTextAttribute(handle, 12);	//красный
			output_map << data.map[i][j] << " ";
			SetConsoleTextAttribute(handle, 15);
		}
			
		output_map << "\n";
	}
	return output_map;
}


void Data::check_for_dead(std::list<Animal*>& animals) {
	auto it(animals.begin());
	while( it != animals.end()) {
		sf::Vector2i temp((*it)->get_coord());
		if ((*it)->get_id() != map[temp.y][temp.x]) {
			auto itTemp = it;
			it++;
			animals.erase(itTemp);
			continue;
		}
		it++;
	}
}

//Проверка и поедание объекта
// desired - жаждить(желать) объект
bool Data::check_desiredObj_and_eating(Animal* animal, std::string desiredObj, int radius) {
	for (int i(-radius); i <= radius; i++)
		for (int j(-radius); j <= radius; j++) {
			sf::Vector2i temp((animal->get_coord().x + i), (animal->get_coord().y + j));
			if ((temp.x) / m_size == 0 and (temp.y) / m_size == 0)
				if (map[temp.y][temp.x] == desiredObj) {
					map[temp.y][temp.x] = map[animal->get_coord().y][animal->get_coord().x];
					map[animal->get_coord().y][animal->get_coord().x] = "0";

					animal->dcoord.x = temp.x - animal->get_coord().x;
					animal->dcoord.y = temp.y - animal->get_coord().y;

					animal->set_coord(temp);
					

					if((animal)->get_behavior().hunger < 0.999)
						(animal)->get_behavior().hunger += 0.2f;
					return true;
				}
		}
	return false;
}

// Случайное движение
// victim - жертва
void Data::randMove(Animal* &animal, std::string victim, int radius) {

	sf::Vector2i offset;
	for (int i(0); i < 25; i++) {
		offset.x = radius - rand() % (2 * radius + 1);
		offset.y = radius - rand() % (2 * radius + 1);
		if ((animal->get_coord().x + offset.x) / m_size == 0 and (animal->get_coord().y + offset.y) / m_size == 0) {
			sf::Vector2i temp((animal->get_coord().x + offset.x), (animal->get_coord().y + offset.y));
			if ((offset.x != 0 or offset.y != 0) and (map[temp.y][temp.x] == "0" or map[temp.y][temp.x] == victim)) {
				map[temp.y][temp.x] = map[animal->get_coord().y][animal->get_coord().x];
				map[animal->get_coord().y][animal->get_coord().x] = "0";
				*animal += offset;
				animal->dcoord.x = offset.x;
				animal->dcoord.y = offset.y;

				if (map[temp.y][temp.x] == victim) {
					if ((animal)->get_behavior().hunger < 0.999)
						(animal)->get_behavior().hunger += 0.2f;
				}
				else
					animal->get_behavior().hunger -= 0.2f;
				return;
			}
		}
	}
}


void Data::deathForHunger(std::list<Animal*>& animals) {
	auto it(animals.begin());
	while( it != animals.end()) {
		//std::cout << "\n\t" << map[(*it)->get_coord().y][(*it)->get_coord().x] << "[" << (*it)->get_coord().x << ";" << (*it)->get_coord().y << "] : " << (*it)->get_behavior().hunger << "\n";
		if ((*it)->get_behavior().hunger <= 0.01) {
			auto itTemp(it);
			
			//(*it)->set_is_dead(true);
			map[(*it)->get_coord().y][(*it)->get_coord().x] = "0";
			//std::cout << "\n\tОт голода умер: " << map[(*it)->get_coord().y][(*it)->get_coord().x] << "[" << (*it)->get_coord().x << ";" << (*it)->get_coord().y << "]" << "\n";
			it++;
			animals.erase(itTemp);
			continue;
		}
		it++;
	}
}

void Data::addAnimal(std::list<Animal*>::iterator &it, std::list<Animal*>& animals, std::string id) {
	Animal* newAnimal;
	if (id == "2") newAnimal = new Plants;
	else if (id == "3") newAnimal = new Herbivore;
	else newAnimal = new Predator;
	sf::Vector2i coord_new_animal(newAnimal->sex(map));
	if (coord_new_animal.x == -1) {
		delete newAnimal;
		return;
	}
		
	if(id == "3")
		(*it)->get_behavior().hunger -= 0.4;
	map[coord_new_animal.y][coord_new_animal.x] = id;
	newAnimal->set_coord(coord_new_animal);
	animals.insert(it, newAnimal);
	//animals.insert(it, newAnimal->init(coord_new_animal));
}

void Data::probability(std::list<Animal*>& animals, int period) {
	auto it(animals.begin());
	Plants tempPlants;
	if (period % tempPlants.getLifeTime() == 0) {
		addAnimal(it, animals, "2");
		tempPlants.setLifeTime(rand() % 2 + 1);
	}
		
	it = animals.end();
	it--;

	int predat_count(0);
	for (it; (*it)->get_id() != "2" and it != animals.begin(); it--) {
		if ((*it)->get_id() != "4") {
			if ((*it)->get_behavior().hunger >= 0.39f) {
				unsigned short percent(1 / (*it)->get_behavior().The_probability_of_breeding), probability(rand() % percent);
				if (probability == 0) {
					addAnimal(it, animals, (*it)->get_id());
				}
			}
		}
		else predat_count++;
	}

	for (predat_count; predat_count < 2; predat_count++) {
		it = animals.end();
		it--;
		addAnimal(it, animals, "4");
	}

}

// Графическое движение, ещё не пришло время
void Data::move(std::list<Animal*>& animals) {
	for (auto it(animals.begin()); it != animals.end(); it++) {
			if ((*it)->get_id() == "4") {

				if (period % (*it)->getMoveTime() == 0) {
					(*it)->setMoveTime(rand() % 3 + 1);
					if ((*it)->get_behavior().hunger <= 0.41) {
						if(check_desiredObj_and_eating((*it), (*it)->get_id_victim(), 2)) continue;
					}
					randMove((*it), (*it)->get_id_victim(), 1);
					continue;
				}
			}
			else if ((*it)->get_id() == "3") {
				if (period % (*it)->getMoveTime() == 0) {
					if ((*it)->get_behavior().hunger <= 0.41) {
						if (check_desiredObj_and_eating((*it), (*it)->get_id_victim(), 1)) continue;
					}
					randMove((*it), (*it)->get_id_victim(), 3);
					(*it)->setMoveTime(rand() % 3 + 1);
				}
			}
			else if ((*it)->get_id() == "2") {
				if ((*it)->get_lifePeriod() % 10 == 0)
					(*it)->get_behavior().hunger = 0;
				(*it)->set_lifePeriod((*it)->get_lifePeriod() + 1);
			}
	}
}