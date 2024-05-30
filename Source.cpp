#include <iostream>

int main() {
    const int rows = 3;
    const int cols = 3;
    int array[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int sum = 0;
    int minElement = array[0][0];
    int maxElement = array[0][0];
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int element = array[i][j];
            sum += element;
            if (element < minElement) {
                minElement = element;
            }
            if (element > maxElement) {
                maxElement = element;
            }
            ++count;
        }
    }

    double average = static_cast<double>(sum) / count;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Min element: " << minElement << std::endl;
    std::cout << "Max element: " << maxElement << std::endl;

    return 0;
}
