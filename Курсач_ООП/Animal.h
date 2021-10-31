#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

struct Behavior {
	float hunger;
	float The_probability_of_breeding;
	Behavior(float a = 0.4f, float b = 0.25f) : hunger(a), The_probability_of_breeding(b) {}
};

class Animal {
protected:
	sf::Vector2i m_coord;
	bool is_dead;
public:
	static short count_of_creatures;
	Animal(int coord_x = 10, int coord_y = 10) : m_coord(coord_x, coord_y), is_dead(false) {
		count_of_creatures++;
	}

	Animal(sf::Vector2i a) : m_coord(a), is_dead(false) {
		count_of_creatures++;
	}

	void set_is_dead(bool set);
	bool const& Is_dead();
	void set_coord(int&& x, int&& y);
	void set_coord(sf::Vector2i a) {
		m_coord = a;
	}

	virtual int const& getMoveTime() { throw "������� getMove"; }
	virtual void setMoveTime(int setMoveTime) { throw "������� setMove"; }

	virtual std::string get_id() {
		throw NULL;
	}

	virtual std::string get_id_victim() {
		throw NULL;
	}

	//����������� ����������� ����������
	virtual Behavior& get_behavior() {
		throw " ����� �� ��������������� ����������� ������: behavior";
	}

	virtual int get_lifePeriod() {
		throw " ����� �� ��������������� ����������� ������: get_lifePeriod";
	}

	virtual void set_lifePeriod( int lifePeriod) {
		throw " ����� �� ��������������� ����������� ������: get_lifePeriod";
	}


	virtual Animal* init(sf::Vector2i) {
		throw "����� init �� ������������� ������";
	}

	virtual sf::Vector2i sex(std::string map[12][12]) {
		throw "����� sex �� ������������� ������";
	}

	sf::Vector2i& get_coord() {
		return m_coord;
	}

	void operator +=(sf::Vector2i addendum) {
		m_coord += addendum;
	}

	void my_draw();
};
