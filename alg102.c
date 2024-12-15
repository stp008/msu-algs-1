#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для сравнения строк для сортировки
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n = 10;  // Максимальное количество слов
    int k = 5;   // Максимальная длина каждого слова
    char input[100];  // Массив для ввода последовательности слов
    char *words[n];   // Массив указателей на строки для хранения слов
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

    // Сортируем слова в алфавитном порядке
    qsort(words, wordCount, sizeof(char *), compareStrings);

    // Вывод слов в алфавитном порядке
    printf("\nПоследовательность в алфавитном порядке:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s", words[i]);
        if (i < wordCount - 1) printf(", ");
    }
    printf(".\n");

    return 0;
}