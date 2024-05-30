#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int rows1 = 5;
    const int cols1 = 10;
    const int rows2 = 5;
    const int cols2 = 5;

    int array1[rows1][cols1];
    int array2[rows2][cols2];

    std::srand(std::time(0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            array1[i][j] = std::rand() % 51;
        }
    }

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            array2[i][j] = array1[i][2 * j] + array1[i][2 * j + 1];
        }
    }

    std::cout << "Array 1 (5x10):" << std::endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            std::cout << array1[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nArray 2 (5x5):" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            std::cout << array2[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
