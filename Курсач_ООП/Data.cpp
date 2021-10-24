#include "Data.h"
#include "Array.h"

#include <iostream>

#include <list>
#include <iterator>

#include <string>

// ���������� ����� �������� 
std::string Data::map[12][12]{};

// ��������� �������� �� ��������� �����
void Data::creature_generation(std::list<Animal*>& object) {
	std::vector<int> index(object.size());
	nonRecRand(index, 100);

	auto it(object.begin());
	for (unsigned long i(0); i < index.size(); i++, it++)
		map[index[i] / 10 + 1][index[i] % 10 + 1] = (*it)->get_id();
}

// ����� ��������� �����
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

//�������� � �������� �������
// desired - �������(������) ������
void Data::check_desiredObj_and_eating(sf::Vector2i& cord, std::string desiredObj, int radius) {
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

// ��������� ��������
// victim - ������
void Data::randMove(sf::Vector2i& cord, std::string victim, int radius) {

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

// ����������� ��������, ��� �� ������ �����
void Data::move(std::list<Animal*>& animals) {

	for (auto it(animals.begin()); it != animals.end(); it++) {
		if (!(*it)->Is_dead())
			if ((*it)->get_id() == "4")
				if (((*it)->get_behavior().hunger > 0.2)) {
					randMove((*it)->get_coord(), (*it)->get_id(), 1);
					continue;
				}
				else {
					check_desiredObj_and_eating((*it)->get_coord(), (*it)->get_id_victim(), 2);
					continue;
				}
			else if ((*it)->get_id() == "3")
				randMove((*it)->get_coord(), (*it)->get_id(), 3);
	}
}