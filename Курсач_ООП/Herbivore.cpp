#include "Herbivore.h"
//#include <iostream>
std::string Herbivore::id_herbivore("3");
std::string Herbivore::id_victim("2");

sf::Vector2i Herbivore::sex(std::string map[][12], std::list<Animal*>::iterator& it) {
   // std::cout << "\n!!! " << get_coord().x << " " << get_coord().y << " !!!\n";
    for (int i((*it)->get_coord().y - 1); i <= (*it)->get_coord().y + 1; i++) {
        for (int j((*it)->get_coord().x - 1); j <= (*it)->get_coord().x + 1; j++) {
            if (map[i][j] == "0") {
                //std::cout << "\n!!! " << j << " " << i << " !!!\n";
                return sf::Vector2i(j, i);
            }
                
        }
    }
    return sf::Vector2i(-1, -1);
}