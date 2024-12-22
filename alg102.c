#include <stdio.h>
#include <string.h>

// Функция для обмена местами двух строк
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Функция сортировки пузырьком
void bubbleSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 10;  // Максимальное количество слов
    int k = 5;   // Максимальная длина каждого слова
    char input[100];  // Массив для ввода последовательности слов
    char *words[10];   // Массив указателей на строки для хранения слов
    int wordCount = 0;

    // Ввод последовательности слов
    printf("Введите последовательность слов (не более 10 слов, каждое до 5 символов):\n");
    fgets(input, sizeof(input), stdin);

    // Убираем символ новой строки, если он есть
    input[strcspn(input, "\n")] = '\0';

    // Разделяем строку на слова с учетом запятой
    char *token = strtok(input, ",");
    while (token != NULL && wordCount < n) {
        // Обрезаем пробелы и сохраняем слова в массив
        while (*token == ' ') token++;  // Убираем начальные пробелы
        words[wordCount++] = token;
        token = strtok(NULL, ",");
    }

    // Вывод последовательности в обратном порядке
    printf("\nПоследовательность в обратном порядке:\n");
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) printf(", ");
    }
    printf(".\n");

    // Сортируем слова в алфавитном порядке с помощью пузырьковой сортировки
    bubbleSort(words, wordCount);

    // Вывод слов в алфавитном порядке
    printf("\nПоследовательность в алфавитном порядке:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s", words[i]);
        if (i < wordCount - 1) printf(", ");
    }
    printf(".\n");

    return 0;
}