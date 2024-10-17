#include <stdbool.h>
#include <stdio.h>
#include <tgmath.h>

bool isInDefinedArea(const double x, const double y) {
    if (pow(x, 2) + pow(y, 2) <= 1 &&
        (y >= -x + 1 || y >= x + 1 || y <= -x - 1 || y <= x - 1)) {
        return true;
    }

    return false;
}


int main(void) {
    int count = 1;

    while (count <= 5) {
        double x;
        double y;

        printf("Введите координату x точки %d: ", count);
        scanf("%lf", &x);

        printf("Введите координату y точки %d: ", count);
        scanf("%lf", &y);

        if (isInDefinedArea(x, y)) {
            printf("Да\n");
        } else {
            printf("Нет\n");
        }

        count++;
    }


    return 0;
}
