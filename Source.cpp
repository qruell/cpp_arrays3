#include <iostream>

int main() {
    int rows, cols, initial_value;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::cout << "Enter the initial value: ";
    std::cin >> initial_value;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    array[0][0] = initial_value;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (j == 0) {
                array[i][j] = array[i - 1][cols - 1] + 1;
            }
            else {
                array[i][j] = array[i][j - 1] + 1;
            }
        }
    }

    std::cout << "Generated 2D array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
