#include <iostream>

int main() {
    int size;

    std::cout << "Enter the diamond size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Please enter a positive number.";
        return 0;
    }

    for (int row = 1; row <= size; ++row) {
        for (int space = 0; space < size - row; ++space)
            std::cout << ' ';
        for (int star = 0; star < 2 * row - 1; ++star)
            std::cout << '*';
        std::cout << '\n';
    }

    for (int row = size - 1; row >= 1; --row) {
        for (int space = 0; space < size - row; ++space)
            std::cout << ' ';
        for (int star = 0; star < 2 * row - 1; ++star)
            std::cout << '*';
        std::cout << '\n';
    }

    return 0;
}
