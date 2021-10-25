#include "Array.h"

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