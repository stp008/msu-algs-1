#include <stdio.h>

void printNumber(char dict[][4], const int k) {
    int size = 0;
    int n = k;

    while (n != 0) {
        n /= 10;
        size++;
    }

    int arabic[size];

    int pos = size;
    n = k;

    while (n != 0) {
        arabic[pos - 1] = n % 10;
        n /= 10;
        pos--;
    }

    if (size == 1) {
        printf("%s\n", dict[arabic[0] - 1]);
    } else {
        char roman[7] = "";
        int decPos = 0;
        for (int i = 0; i < arabic[0]; i++) {
            roman[i] = dict[9][0];
            decPos = i;
        }
        if (arabic[1] != 0) {
            for (int i = 0; i < 4; i++) {
                roman[decPos + i + 1] = dict[arabic[1] - 1][i];
            }
        }
        printf("%s\n", roman);
    }
}

/* Написать программу на Паскале.
 * Ввести целое k, для 1≤k≤39 вывести значение k римскими цифрами, используя заглавные буквы 'I', 'V' и 'X' для римских цифр 1, 5 и 10, соответственно.
 * Если значение k лежит вне указанного диапазона, то вывести 0.
 * Автотест: Полученную программу можно проверить в системе автоматической проверки - задача 7.23)
 */
int main(void) {
    int k;

    printf("Введите целое число: ");
    scanf("%d", &k);

    char dict[10][4] = {
        "I",
        "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"
    };

    char num[3];
    sprintf(num, "%d", k);

    if (k < 1 || k > 39) {
        printf("%d\n", 0);
    } else {
        printNumber(dict, k);
    }

    return 0;
}
