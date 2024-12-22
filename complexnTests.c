#include "complexn.h"
#include <stdio.h>
#include <assert.h>

// Тесты
void test_add() {
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};
    Complex result = add(a, b);
    Complex expected = {4.0, 6.0};
    assert(compareComplex(result, expected, 1e-6) && "Ошибка в функции add");
    printf("Тест add пройден.\n");
}

void test_subtract() {
    Complex a = {5.0, 6.0};
    Complex b = {3.0, 4.0};
    Complex result = subtract(a, b);
    Complex expected = {2.0, 2.0};
    assert(compareComplex(result, expected, 1e-6) && "Ошибка в функции subtract");
    printf("Тест subtract пройден.\n");
}

void test_multiply() {
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};
    Complex result = multiply(a, b);
    Complex expected = {-5.0, 10.0};

    assert(compareComplex(result, expected, 1e-6) && "Ошибка в функции multiply");
    printf("Тест multiply пройден.\n");
}

void test_divide() {
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};
    Complex result = divide(a, b);
    Complex expected = {0.44, 0.08}; // Примерный результат
    assert(compareComplex(result, expected, 1e-2) && "Ошибка в функции divide");
    printf("Тест divide пройден.\n");
}

void test_power() {
    Complex a = {2.0, 1.0};
    int n = 3;
    Complex result = power(a, n);
    Complex expected = {2.0, 11.0}; // Результат (2+i)^3 = -2+11i
    assert(compareComplex(result, expected, 1e-6) && "Ошибка в функции power");
    printf("Тест power пройден.\n");
}

void test_printComplex() {
    Complex a = {3.0, 4.0};
    printf("Ожидается: 3.00 + 4.00i\n");
    printf("Реальный результат: ");
    printComplex(a);
    Complex b = {3.0, -4.0};
    printf("Ожидается: 3.00 - 4.00i\n");
    printf("Реальный результат: ");
    printComplex(b);
    printf("Тест printComplex пройден (визуальная проверка).\n");
}

int main() {
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_power();
    test_printComplex();
    printf("Все тесты пройдены.\n");
    return 0;
}