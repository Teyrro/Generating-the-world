#include "Array.h"
#include "Animal.h"
#include "Data.h"

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

sf::Vector2i sex(Animal& animal) {
    for (int i(animal.get_coord().y - 1); i <= animal.get_coord().y + 1; i++) {
        for (int j(animal.get_coord().x - 1); j <= animal.get_coord().x + 1; j++) {
            if (Data::map[i][j] == "0")
                return sf::Vector2i(j, i);
        }
    }
}