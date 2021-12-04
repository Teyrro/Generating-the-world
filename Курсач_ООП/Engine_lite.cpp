#include "Engine_lite.h"

int Engine_lite::count_f{ 1 };

float remainder(float a) {
	return (a - static_cast<int> (a));
}

void Engine_lite::draw_location(sf::RenderWindow& window) {
	
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++) {
			obj.setTexture(texture);
			switch (renderedMap[i][j]){
			case 0:
				obj.setTextureRect(sf::IntRect(0, 0, obj_size, obj_size));
				break;
			case 1:
				obj.setTextureRect(sf::IntRect(6 * obj_size, 0, obj_size, obj_size));
				break;
			case 2:
				obj.setTextureRect(sf::IntRect(10 * obj_size, 0, obj_size, obj_size));
				break;
			case 3:
				obj.setTextureRect(sf::IntRect(8 * obj_size, 0, obj_size, obj_size));
				break;
			case 4:
				obj.setTextureRect(sf::IntRect(12 * obj_size, 0, obj_size, obj_size));
				break;
			case 5:
				obj.setTextureRect(sf::IntRect(7 * obj_size, 0, obj_size, obj_size));
				break;
			case 6:
				obj.setTextureRect(sf::IntRect(5 * obj_size, 0, obj_size, obj_size));
				break;
			case 7:
				obj.setTextureRect(sf::IntRect(11 * obj_size, 0, obj_size, obj_size));
				break;
			case 8:
				obj.setTextureRect(sf::IntRect(9 * obj_size, 0, obj_size, obj_size));
				break;
			case 9:
				obj.setTextureRect(sf::IntRect(4 * obj_size, 0, obj_size, obj_size));
				break;
			}
			obj.setPosition(i * obj_size, j * obj_size);
			window.draw(obj);
		}
			
	//obj.setTextureRect(sf::IntRect(0, 0, obj_size, obj_size));
	//for (int i(0); i < obj_size *12; i += obj_size) {
	//	for (int j(0); j < obj_size * 12; j += obj_size) {
	//		obj.setPosition(i, j);
	//		window.draw(obj);
	//	}
	//	
	//}
}

void Engine_lite::draw_obj(sf::RenderWindow& window) {
	int k = 1, f = 0;
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
			sf::Vector2f offset_object(((*it)->dcoord.x * obj_size / 119.f) * count_f, (((*it)->dcoord.y * obj_size / 119.f) * count_f));
			
			sf::Vector2f hui_v_palito(start_coord + offset_object);
			obj.setPosition(hui_v_palito);
			window.draw(obj);

			//std::cout << "( " << hui_v_palito.x << " " << hui_v_palito.y << " ) \n";
			f = 1;
		
		if (((*it)->dcoord.x != 0 or (*it)->dcoord.y != 0) and count_f == 119) {
			(*it)->dcoord.x = 0;
			(*it)->dcoord.y = 0;
		}
	}
	count_f++;
}

void Engine_lite::createMap(int map[][12]) {
	srand((unsigned int)time(NULL));
	int lakeCount = rand() % 12 +5;
	std::vector<int> lake;
	lake.resize(lakeCount);
	map[0][0] = 1;
	map[11][11] = 2;
	map[11][0] = 3;
	map[0][11] = 4;
	for (int i = 1; i < 11; i++) {
		map[i][0] = 5;
		map[0][i] = 6;
		map[i][11] = 7;
		map[11][i] = 8;
	}
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 11; j++)
			map[i][j] = 0;

	sf::Vector2i lakeCord;
	for (int i = 0; i < lakeCount; i++) {
		do {
			lakeCord.x = rand() % 10 + 1;
			lakeCord.y = rand() % 10 + 1;
		} while (map[lakeCord.x][lakeCord.y] != 0);
		map[lakeCord.x][lakeCord.y] = 9;
	}
		
	
}

