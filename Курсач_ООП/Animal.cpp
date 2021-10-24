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