#include <iostream>

int main() {
    const int rows = 3;
    const int cols = 4;
    int array[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int rowSums[rows] = { 0 };
    int colSums[cols] = { 0 };
    int totalSum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int element = array[i][j];
            rowSums[i] += element;
            colSums[j] += element;
            totalSum += element;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "| " << rowSums[i] << std::endl;
    }

    for (int j = 0; j < cols; ++j) {
        std::cout << "--------";
    }
    std::cout << std::endl;

    for (int j = 0; j < cols; ++j) {
        std::cout << colSums[j] << "\t";
    }
    std::cout << "| " << totalSum << std::endl;

    return 0;
}
