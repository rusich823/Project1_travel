#include "Matrix.h"
#include <random>
#include <vector> 

std::vector<std::vector<int>> Matr_Create(int nCities) {

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < nCities; i++) {

        std::vector<int> row(nCities, 0);

        matrix.push_back(row);
    }

    return matrix;
}

// Передаем по ссылке (&), чтобы изменения внутри функции применились к оригинальной матрице
void fillRandomMatrix(std::vector<std::vector<int>>& matrix, int minCost, int maxCost) {
    // Вектор сам знает свой размер, nCities больше передавать не нужно!
    int nCities = matrix.size();

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(minCost, maxCost);

    // Нам всё еще нужны два цикла, чтобы пройтись по КАЖДОЙ ячейке таблицы (строка i, столбец j)
    for (int i = 0; i < nCities; i++) {
        for (int j = 0; j < nCities; j++) {

            // Если номер строки равен номеру столбца — это диагональ (город сам в себя)
            if (i == j) {
                matrix[i][j] = 0;
            }
            // Для всех остальных путей генерируем случайную стоимость
            else {
                matrix[i][j] = distribution(generator);
            }

        }
    }
}
bool isVisited(const std::vector<int>& path, int city) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == city) return true; // Нашли город в пути
    }
    return false; // Города еще нет в пути
}
