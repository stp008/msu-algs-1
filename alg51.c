#include <stdio.h>

/*
 * С клавиатуры вводятся два числа и знак операции между ними "+", "-", " * " или "/" (порядок ввода - произвольный).
 * Выполнить над числами соответствующее действие и напечатать результат.
 * Указание: использовать оператор варианта.
 */
int main(void) {
    double x;
    double y;
    char operation;
    double result;

    printf("Введите первое число: ");
    scanf("%lf", &x);

    printf("Введите второе число: ");
    scanf("%lf", &y);

    printf("Введите операцию: ");
    scanf("%s", &operation);

    if (operation == '+') {
        result = x + y;
    } else if (operation == '-') {
        result = x - y;
    } else if (operation == '*') {
        result = x * y;
    } else if (operation == '/') {
        result = x / y;
    } else {
        printf("Введена неизвестная операция");
        return 1;
    }

    printf("Результат операции \"%c\" над числами %f и %f: %f", operation, x, y, result);

    return 0;
}
