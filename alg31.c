#include <stdio.h>
#include <string.h>

int main(void) {
    double num;
    printf("Введите число x: ");
    scanf("%lf",&num);

    char arr[25];
    sprintf(arr, "%f", num);

    char d;
    char delimiter = '.';

    for (int i = 0; i < sizeof(arr); i++) {
        if (delimiter == arr[i]) {
            d = arr[i + 1];
            break;
        }
    }

    printf("Значение переменной d: %c", d);
    return 0;
}
