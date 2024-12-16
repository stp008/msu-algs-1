#include <stdio.h>

int main() {
    typedef enum { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec } month;
    int d;
    int month_number;
    month m;

    printf("Введите номер месяца (1-12): ");
    if (scanf("%d", &month_number) != 1 || month_number < 1 || month_number > 12) {
        printf("Ошибка ввода! Введите число от 1 до 12.\n");
        return 1;
    }

    m = (month)(month_number - 1);

    switch (m) {
        case jan: case mar: case may: case jul: case aug: case oct: case dec:
            d = 31;
        break;
        case apr: case jun: case sep: case nov:
            d = 30;
        break;
        case feb:
            d = 28;
        break;
    }

    printf("Количество дней в месяце: %d\n", d);

    return 0;
}
