#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Константа, содержащая символы, которые будем искать в строке
const char v[] = "aeiou";

// Функция для проверки, является ли символ частью строки v
bool isInV(char c) {
    for (int i = 0; i < strlen(v); i++) {
        if (c == v[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    char s[21];  // Строка длиной не более 20 символов (плюс один символ для завершения)
    int k = 0;   // Счетчик вхождений

    // Ввод строки
    printf("Введите строку (не более 20 символов): ");
    fgets(s, sizeof(s), stdin);

    // Убираем символ новой строки, если он есть
    s[strcspn(s, "\n")] = '\0';

    // Проходим по строке и считаем вхождения символов из v
    for (int i = 0; i < strlen(s); i++) {
        if (isInV(s[i])) {
            k++;
        }
    }

    // Выводим результат
    printf("Количество вхождений символов из 'aeiou' в строку: %d\n", k);

    return 0;
}
