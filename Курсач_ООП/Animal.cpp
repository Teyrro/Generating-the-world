#include "Animal.h"
short Animal::count_of_creatures = 0;

void Animal::my_draw() {

}

void Animal::set_is_dead(bool set) {
	is_dead = set;
}

bool const& Animal::Is_dead() {
	return is_dead;
}

// ����������� ���������� ���������� memory � ������������ std::move()
void Animal::set_coord(int&& x, int&& y) {
	m_coord.x = std::move(x);
	m_coord.y = std::move(y);
}

//����������� ����������� ����������
int const& Animal::getMoveTime() { throw "������� getMove"; }
void Animal::setMoveTime(int setMoveTime) { throw "������� setMove"; }

std::string Animal::get_id() {
	throw NULL;
}

std::string Animal::get_id_victim() {
	throw NULL;
}


Behavior& Animal::get_behavior() {
	throw " ����� �� ��������������� ����������� ������: behavior";
}

int Animal::get_lifePeriod() {
	throw " ����� �� ��������������� ����������� ������: get_lifePeriod";
}

void Animal::set_lifePeriod(int lifePeriod) {
	throw " ����� �� ��������������� ����������� ������: get_lifePeriod";
}


Animal* Animal::init(sf::Vector2i) {
	throw "����� init �� ������������� ������";
}

sf::Vector2i Animal::sex(std::string map[12][12], std::list<Animal*>::iterator& it) {
	throw "����� sex �� ������������� ������";
}