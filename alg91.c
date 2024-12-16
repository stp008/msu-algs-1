#include <stdio.h>
#include <stdlib.h>

// Функция для вывода матрицы
void printMatrix(int matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для нахождения максимального элемента и его индекса
void findMaxElement(int matrix[5][5], int *maxVal, int *maxI, int *maxJ) {
    *maxVal = matrix[0][0];
    *maxI = 0;
    *maxJ = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] > *maxVal) {
                *maxVal = matrix[i][j];
                *maxI = i;
                *maxJ = j;
            }
        }
    }
}

// Функция для нахождения минимального элемента ниже главной диагонали
void findMinBelowDiagonal(int matrix[5][5], int *minVal, int *minI, int *minJ) {
    *minVal = matrix[1][0];  // Первый элемент под главной диагональю
    *minI = 1;
    *minJ = 0;

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {  // Элементы ниже главной диагонали
            if (matrix[i][j] < *minVal) {
                *minVal = matrix[i][j];
                *minI = i;
                *minJ = j;
            }
        }
    }
}

// Функция для перестановки строк 1 и 5
void swapRows(int matrix[5][5]) {
    int temp;
    for (int j = 0; j < 5; j++) {
        temp = matrix[0][j];
        matrix[0][j] = matrix[4][j];
        matrix[4][j] = temp;
    }
}

int main() {
    int matrix[5][5];
    int maxVal, maxI, maxJ, minVal, minI, minJ;

    // Заполнение матрицы случайными числами от -50 до 50
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = rand() % 101 - 50;  // Числа от -50 до 50
        }
    }

    // Вывод матрицы
    printf("Матрица B:\n");
    printMatrix(matrix);

    // Находим максимальный элемент и его индекс
    findMaxElement(matrix, &maxVal, &maxI, &maxJ);
    printf("\nНаибольшее значение в матрице: %d, его индекс: (%d, %d)\n", maxVal, maxI + 1, maxJ + 1);

    // Находим минимальный элемент ниже главной диагонали и его индекс
    findMinBelowDiagonal(matrix, &minVal, &minI, &minJ);
    printf("\nМинимальное значение среди элементов ниже главной диагонали: %d, его индекс: (%d, %d)\n", minVal, minI + 1, minJ + 1);

    // Переставляем строки 1 и 5
    swapRows(matrix);

    // Выводим измененную матрицу
    printf("\nИзмененная матрица после перестановки строк 1 и 5:\n");
    printMatrix(matrix);

    return 0;
}