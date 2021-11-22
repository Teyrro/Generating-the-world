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

// обязательно подключить библиотеку memory и использовать std::move()
void Animal::set_coord(int&& x, int&& y) {
	m_coord.x = std::move(x);
	m_coord.y = std::move(y);
}

//Обязательно Используйте исключения
int const& Animal::getMoveTime() { throw "Вызвана getMove"; }
void Animal::setMoveTime(int setMoveTime) { throw "Вызвана setMove"; }

std::string Animal::get_id() {
	throw NULL;
}

std::string Animal::get_id_victim() {
	throw NULL;
}


Behavior& Animal::get_behavior() {
	throw " Вызов не переопределённой виртуальной фунции: behavior";
}

int Animal::get_lifePeriod() {
	throw " Вызов не переопределённой виртуальной фунции: get_lifePeriod";
}

void Animal::set_lifePeriod(int lifePeriod) {
	throw " Вызов не переопределённой виртуальной фунции: get_lifePeriod";
}


Animal* Animal::init(sf::Vector2i) {
	throw "Вызов init из родительского класса";
}

sf::Vector2i Animal::sex(std::string map[12][12], std::list<Animal*>::iterator& it) {
	throw "Вызов sex из родительского класса";
}