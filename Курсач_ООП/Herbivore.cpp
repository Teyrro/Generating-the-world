#include "Herbivore.h"
std::string Herbivore::id_herbivore("3");
std::string Herbivore::id_victim("2");

sf::Vector2i Herbivore::sex(std::string map[][12]) {
    for (int i(get_coord().y - 1); i <= get_coord().y + 1; i++) {
        for (int j(get_coord().x - 1); j <= get_coord().x + 1; j++) {
            if (map[i][j] == "0")
                return sf::Vector2i(j, i);
        }
    }
    return sf::Vector2i(-1, -1);
}