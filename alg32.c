#include <stdio.h>
#include <tgmath.h>

int main(void) {
    double x1;
    double y1;

    double x2;
    double y2;

    printf("Введите координату x1: ");
    scanf("%lf",&x1);

    printf("Введите координату y1: ");
    scanf("%lf",&y1);

    printf("Введите координату x2: ");
    scanf("%lf",&x2);

    printf("Введите координату y2: ");
    scanf("%lf",&y2);

    double d = sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2));


    printf("Расстояние между точками (%f, %f) и (%f, %f): %f", x1, y1, x2, y2, d);
    return 0;
}
