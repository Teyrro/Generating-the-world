#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include "Plants.h"
#include "Predator.h"
#include "Array.h"

#include <iostream>
#include <list>
#include <iterator>
#include <string>

class Data {
	const short m_size = 12;
	std::string map[12][12];
public:
	Data() {
		for (int i(0); i < m_size; i++) {
			if(i > 0 and i < 11)
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

	friend std::ostream& operator << (std::ostream& output_map, Data map);

	// desired - жаждить(желать) объект
	void check(sf::Vector2i& cord, std::string desiredObj, int radius) {
		for (int i(-radius); i <= radius; i++)
			for (int j(-radius); j <= radius; j++) {
				sf::Vector2i temp((cord.x + i), (cord.y + j));
				if ((temp.x) / m_size == 0 and (temp.y) / m_size == 0)
					if (map[temp.y][temp.x] == desiredObj) {
						map[temp.y][temp.x] = map[cord.y][cord.x];
						map[cord.y][cord.x] = "0";
						cord.x += i;
						cord.y += j;
						break;
					}
			}
	}

	// victim - жертва
	void randMove(sf::Vector2i& cord, std::string victim, int radius) {

		sf::Vector2i offset;
		while (1) {
			offset.x = radius - rand() % (2 * radius + 1);
			offset.y = radius - rand() % (2 * radius + 1);
			if ((cord.x + offset.x) / m_size == 0 and (cord.y + offset.y) / m_size == 0) {
				sf::Vector2i temp((cord.x + offset.x), (cord.y + offset.y));
				if ((offset.x != 0 or offset.y != 0) and (map[temp.y][temp.x] == "0" or map[temp.y][temp.x] == victim)) {
					map[temp.y][temp.x] = map[cord.y][cord.x];
					map[cord.y][cord.x] = "0";
					cord.x += offset.x;
					cord.y += offset.y;
					break;
				}
			}
		}
	}

	void creature_generation(std::list<Animal*>& object) {
		std::vector<int> index(object.size());
		nonRecRand(index, 100);
		auto it(object.begin());
		for (unsigned long i(0); i < index.size(); i++, it++) {
			map[index[i] / 10 + 1][index[i] % 10 + 1] = (*it)->get_id();
		}
	}

	void move(Animal& oblect);
};