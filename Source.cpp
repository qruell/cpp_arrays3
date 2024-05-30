#include <iostream>
#include <cstdlib>
#include <ctime>

void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void shiftLeft(int** array, int rows, int cols, int shifts) {
    shifts %= cols;
    int* temp = new int[cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[j] = array[i][(j + shifts) % cols];
        }
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[j];
        }
    }
    delete[] temp;
}

void shiftRight(int** array, int rows, int cols, int shifts) {
    shifts %= cols;
    int* temp = new int[cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[(j + shifts) % cols] = array[i][j];
        }
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[j];
        }
    }
    delete[] temp;
}

void shiftUp(int** array, int rows, int cols, int shifts) {
    shifts %= rows;
    int** temp = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[i][j] = array[(i + shifts) % rows][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

void shiftDown(int** array, int rows, int cols, int shifts) {
    shifts %= rows;
    int** temp = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[(i + shifts) % rows][j] = array[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = temp[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}

int main() {
    int rows, cols, shifts;
    char direction;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    std::srand(std::time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = std::rand() % 100;
        }
    }

    std::cout << "Original array:" << std::endl;
    printArray(array, rows, cols);

    std::cout << "Enter the number of shifts: ";
    std::cin >> shifts;
    std::cout << "Enter the direction (l=left, r=right, u=up, d=down): ";
    std::cin >> direction;

    switch (direction) {
    case 'l':
        shiftLeft(array, rows, cols, shifts);
        break;
    case 'r':
        shiftRight(array, rows, cols, shifts);
        break;
    case 'u':
        shiftUp(array, rows, cols, shifts);
        break;
    case 'd':
        shiftDown(array, rows, cols, shifts);
        break;
    default:
        std::cout << "Invalid direction" << std::endl;
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
        return 1;
    }

    std::cout << "Shifted array:" << std::endl;
    printArray(array, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
