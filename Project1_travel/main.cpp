#include <iostream>
#include "Matrix.h"
#include <random>
#include <vector> 

int main() {

    for (int i = 0; i < N; i++) {
        
        if (!isVisited(path, i) && matr[current_city][i] != 0) {

            path.push_back(i);
            path.pop_back();    
        }
    }
}