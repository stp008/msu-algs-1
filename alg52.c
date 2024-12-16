#include <stdio.h>

int main() {
    int k;

    // Ввод числа k
    printf("Введите целое число k (1 <= k <= 39): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > 39) {
        printf("0\n");
        return 0;
    }

    // Вывод десятков (X = 10)
    for (int i = 0; i < k / 10; i++) {
        printf("X");
    }

    switch (k % 10) {
        case 1: printf("I"); break;
        case 2: printf("II"); break;
        case 3: printf("III"); break;
        case 4: printf("IV"); break;
        case 5: printf("V"); break;
        case 6: printf("VI"); break;
        case 7: printf("VII"); break;
        case 8: printf("VIII"); break;
        case 9: printf("IX"); break;
    }

    printf("\n");
    return 0;
}
