#include "Engine_lite.h"

int Engine_lite::count_f{ 1 };

float remainder(float a) {
	return (a - static_cast<int> (a));
}

void Engine_lite::draw_location(sf::RenderWindow& window) {
	obj.setTexture(texture);
	obj.setTextureRect(sf::IntRect(0, 0, obj_size, obj_size));
	for (int i(0); i < obj_size *12; i += obj_size) {
		for (int j(0); j < obj_size * 12; j += obj_size) {
			obj.setPosition(i, j);
			window.draw(obj);
		}
		
	}
}

void Engine_lite::draw_obj(sf::RenderWindow& window) {
	int k = 1;
	std::list<Animal*> ::iterator it(array_all_classes.begin());
	for (it; it != array_all_classes.end(); it++) {
		if ((*it)->get_id() == "2" and k != 2) {
			obj.setTexture(texture);
			obj.setTextureRect(sf::IntRect(3* obj_size, 0, obj_size, obj_size));
			k = 2;
		}
		else if ((*it)->get_id() == "3" and k != 3) {
				obj.setTexture(texture);
				obj.setTextureRect(sf::IntRect(2* obj_size, 0, obj_size, obj_size));
				k = 3;
		}
		else if ((*it)->get_id() == "4" and k != 4) {
				obj.setTexture(texture);
				obj.setTextureRect(sf::IntRect(1* obj_size, 0, obj_size, obj_size));
				k = 4;
		}

		sf::Vector2f start_coord(((*it)->get_coord().x - (*it)->dcoord.x) * obj_size, ((*it)->get_coord().y - (*it)->dcoord.y) * obj_size);
		sf::Vector2f offset_object(((*it)->dcoord.x * obj_size / 120.f) * count_f, ((*it)->dcoord.y * obj_size / 120.f) * count_f);
		
		sf::Vector2f hui_v_palito(start_coord + offset_object);
		obj.setPosition(hui_v_palito);
		window.draw(obj);
		
		if (((*it)->dcoord.x != 0 or (*it)->dcoord.y != 0) and count_f == 119) {
			(*it)->dcoord.x = 0;
			(*it)->dcoord.y = 0;
		}
	}
	count_f++;

}

