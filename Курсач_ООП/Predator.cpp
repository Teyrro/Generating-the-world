#include "Predator.h"

std::string Predator::id_predator("4");
std::string Predator::id_victim("3");

sf::Vector2i Predator::sex(std::string map[][12]) {
    sf::Vector2i orig_cord;
    for (int i(0); i < 30; i++) {
        if (rand() % 2)
            orig_cord = sf::Vector2i(rand() % 10 + 1, 1);
        else orig_cord = sf::Vector2i(rand() % 10 + 1, 10);
        if (rand() % 2)
            orig_cord = sf::Vector2i(orig_cord.y, orig_cord.x);
        if (map[orig_cord.y][orig_cord.x] == "0")
            return orig_cord;
    }
    return sf::Vector2i(-1, -1);
}