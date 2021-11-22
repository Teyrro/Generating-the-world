#include "Plants.h"
std::string Plants::id_plant("2");
int Plants::m_lifeTime(2);

sf::Vector2i Plants::sex(std::string map[][12], std::list<Animal*>::iterator& it) {
    sf::Vector2i orig_cord;
    int randCoord;
    for (int i(0); i < 30; i++) {
        randCoord = rand() % 100;
        orig_cord.x = randCoord / 10 + 1;
        orig_cord.y = randCoord % 10 + 1;
        return orig_cord;
    }
    return sf::Vector2i(-1, -1);
}