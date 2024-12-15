#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Функция для нахождения корней квадратного уравнения x^2 + px + q = 0
bool Roots(double p, double q, double *x1, double *x2) {
    double D = p * p - 4 * q;  // Вычисляем дискриминант
    if (D >= 0) {
        *x1 = (-p + sqrt(D)) / 2;  // Первый корень
        *x2 = (-p - sqrt(D)) / 2;  // Второй корень
        return true;
    }
    return false;  // Нет вещественных корней
}

int main() {
    double a, b;

    // Ввод данных
    printf("Введите a и b: ");
    scanf("%lf %lf", &a, &b);

    double x1_1, x2_1, x1_2, x2_2;

    // Проверяем, имеют ли оба уравнения вещественные корни
    bool rootsExistFirst = Roots(6.2, a * a, &x1_1, &x2_1);
    bool rootsExistSecond = Roots(a, b - 1, &x1_2, &x2_2);

    if (rootsExistFirst && rootsExistSecond) {
        // Если оба уравнения имеют вещественные корни, выводим true
        printf("true\n");

        // Проверяем, лежат ли корни первого уравнения между корнями второго
        if ((x1_1 > x1_2 && x1_1 < x2_2 && x2_1 > x1_2 && x2_1 < x2_2) ||
            (x1_1 > x2_2 && x1_1 < x1_2 && x2_1 > x2_2 && x2_1 < x1_2)) {
            printf("true\n");
            } else {
                printf("false\n");
            }
    } else {
        // Если хотя бы одно уравнение не имеет вещественных корней
        printf("false\n");
    }

    return 0;
}
