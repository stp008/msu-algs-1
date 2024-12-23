#include <stdio.h>


#define MAX_SIZE 100

int main() {
    int N;

    // Вводим количество элементов
    printf("Введите количество элементов N (0 < N <= 100): ");
    scanf("%d", &N);

    // Проверка на корректность введенного числа
    if (N <= 0 || N > 100) {
        printf("Ошибка: количество элементов должно быть в пределах от 1 до 100.\n");
        return 1;  // Завершаем выполнение программы
    }

    int array[MAX_SIZE];  // Массив исходных данных
    int zero_indices[MAX_SIZE];  // Массив для хранения номеров нулевых элементов
    int zero_count = 0;  // Счётчик нулевых элементов

    // Вводим элементы последовательности
    printf("Введите %d элементов последовательности:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
        if (array[i] == 0) {
            zero_indices[zero_count++] = i;  // Записываем индекс нулевого элемента
        }
    }

    // Выводим результаты
    printf("Количество элементов N: %d\n", N);
    printf("Количество нулевых элементов M: %d\n", zero_count);

    if (zero_count == 0) {
        printf("Нулевых элементов нет!\n");
    } else {
        printf("Номера нулевых элементов:\n");
        for (int i = 0; i < zero_count; i++) {
            printf("%d ", zero_indices[i]);
        }
        printf("\n");
    }

    return 0;
}
