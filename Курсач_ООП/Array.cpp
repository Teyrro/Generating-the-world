#include "Array.h"
#include "Animal.h"
#include "Herbivore.h"
#include "Predator.h"
#include "Plants.h"
#include <iostream>
#include <vector>
#include <ctime>

void nonRecRand(std::vector<int>& arr, int maxRand) {
    srand((unsigned int)time(NULL));

    //assert(arrSize > maxRand && "nonRecRand: неверные входные данные");
    int  prevRand = 0;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % ((maxRand - prevRand) / (arr.size() - i)) + 1 + prevRand;
        prevRand = arr[i];
    }

    arr::mix(arr);
}

void arr::mix(std::vector<int>& arr) {
    int a, b, c;
    for (int i = 0; i < arr.size(); i++) {
        a = rand() % arr.size();
        b = rand() % arr.size();
        c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }
}

sf::Vector2i Herbivore::sex(std::string map[][12]) {
    for (int i(get_coord().y - 1); i <= get_coord().y + 1; i++) {
        for (int j(get_coord().x - 1); j <= get_coord().x + 1; j++) {
            if (map[i][j] == "0")
                return sf::Vector2i(j, i);
        }
    }
    return sf::Vector2i(-1, -1);
}

sf::Vector2i Predator::sex(std::string map[][12]){
    sf::Vector2i orig_cord;
    for(int i(0); i < 30; i++){
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

sf::Vector2i Plants::sex(std::string map[][12]) {
    sf::Vector2i orig_cord;
    int randCoord;
    for(int i(0); i < 30; i++) {
        randCoord = rand() % 100;
        orig_cord.x = randCoord / 10 + 1;
        orig_cord.y = randCoord % 10 + 1;
        return orig_cord;
    }
    return sf::Vector2i(-1, -1);
}
