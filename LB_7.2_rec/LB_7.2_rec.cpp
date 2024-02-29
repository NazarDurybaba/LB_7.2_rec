#include <iostream>
#include <cstdlib>
#include <ctime>

// Максимальний розмір матриці
const int MAX_SIZE = 100;

// Рекурсивна функція для генерації матриці
void generateMatrix(int matrix[MAX_SIZE][MAX_SIZE], int i, int j, int k, int n) {
    if (i < k) {
        if (j < n) {
            matrix[i][j] = std::rand() % 100 + 1;
            generateMatrix(matrix, i, j + 1, k, n);
        }
        else {
            generateMatrix(matrix, i + 1, 0, k, n);
        }
    }
}

// Рекурсивна функція для виведення матриці
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int i, int j, int k, int n) {
    if (i < k) {
        if (j < n) {
            std::cout << matrix[i][j] << "\t";
            printMatrix(matrix, i, j + 1, k, n);
        }
        else {
            std::cout << "\n";
            printMatrix(matrix, i + 1, 0, k, n);
        }
    }
}

// Рекурсивна функція для знаходження максимального елементу в рядку
int maxInRow(int matrix[MAX_SIZE][MAX_SIZE], int i, int j, int n, int maxElem) {
    if (j < n) {
        if (matrix[i][j] > maxElem) {
            maxElem = matrix[i][j];
        }
        return maxInRow(matrix, i, j + 1, n, maxElem);
    }
    else {
        return maxElem;
    }
}

// Рекурсивна функція для знаходження суми максимальних елементів у парних рядках
int sumMaxInEvenRows(int matrix[MAX_SIZE][MAX_SIZE], int i, int n, int k, int sum) {
    if (i < k) {
        if (i % 2 == 0) {
            sum += maxInRow(matrix, i, 0, n, INT_MIN);
        }
        return sumMaxInEvenRows(matrix, i + 1, n, k, sum);
    }
    else {
        return sum;
    }
}

int main() {
    int k, n;
    std::cout << "Rozmir (k n): ";
    std::cin >> k >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    std::srand(std::time(0));
    generateMatrix(matrix, 0, 0, k, n);

    std::cout << "Matrix:\n";
    printMatrix(matrix, 0, 0, k, n);

    int sum = sumMaxInEvenRows(matrix, 0, n, k, 0);
    std::cout << "Sum: " << sum << "\n";

    return 0;
}
