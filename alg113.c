#include <stdio.h>
#include <math.h>

// Структура для хранения координат точки
typedef struct {
    double x;
    double y;
} Point;

// Функция для вычисления расстояния между двумя точками
double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int main() {
    // Ввод координат трех вершин треугольника
    Point A, B, C;

    printf("Введите координаты вершины A (x1, y1): ");
    scanf("%lf %lf", &A.x, &A.y);

    printf("Введите координаты вершины B (x2, y2): ");
    scanf("%lf %lf", &B.x, &B.y);

    printf("Введите координаты вершины C (x3, y3): ");
    scanf("%lf %lf", &C.x, &C.y);

    // Вычисление длин сторон треугольника
    double AB = distance(A, B);
    double BC = distance(B, C);
    double CA = distance(C, A);

    // Вывод длин сторон
    printf("Длина стороны AB: %.2lf\n", AB);
    printf("Длина стороны BC: %.2lf\n", BC);
    printf("Длина стороны CA: %.2lf\n", CA);

    return 0;
}
