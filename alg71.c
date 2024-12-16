#include <stdio.h>
#include <stdlib.h>

// Функция для вычисления косинуса по ряду Тейлора
double cosine(double x, double eps) {
    double result = 1.0;  // Начальное значение 1 (0-й элемент ряда)
    double term = 1.0;    // Начальное слагаемое
    int n = 1;            // Индекс для вычисления степени и факториала

    // Пока текущее слагаемое больше или равно eps
    while (abs(term) >= eps) {
        term *= -x * x / (2 * n * (2 * n - 1));  // Следующее слагаемое
        result += term;  // Добавляем слагаемое к результату
        n++;  // Увеличиваем индекс для вычисления следующего слагаемого
    }

    return result;
}

int main() {
    double x;
    double eps = 1e-6;  // Точность
    int count = 0;

    // Внешний цикл для ввода x (не более 10 штук)
    while (count < 10) {
        printf("Введите x (в диапазоне [0, 3]: ");
        if (scanf("%lf", &x) != 1) {
            printf("Ошибка ввода!\n");
            break;
        }

        // Проверяем, что x находится в диапазоне [0, 3]
        if (x < 0 || x > 3) {
            break;  // Прерываем цикл
        }

        // Вычисляем cos(x)
        double result = cosine(x, eps);

        // Выводим результат
        printf("cos(%.6lf) = %.6lf\n", x, result);

        count++;  // Увеличиваем счетчик попыток ввода
    }

    return 0;
}
