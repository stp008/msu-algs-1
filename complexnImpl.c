#include "complexn.h"
#include <stdio.h>
#include <math.h>

// Функция для сравнения двух комплексных чисел
int compareComplex(Complex a, Complex b, double epsilon) {
    return fabs(a.real - b.real) < epsilon && fabs(a.img - b.img) < epsilon;
}

// Функция для сложения комплексных чисел
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}

// Функция для вычитания комплексных чисел
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.img = a.img - b.img;
    return result;
}

// Функция для умножения комплексных чисел
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.img * b.img;
    result.img = a.img * b.real + a.real * b.img;
    return result;
}

// Функция для деления комплексных чисел
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.img * b.img;
    result.real = (a.real * b.real + a.img * b.img) / denominator;
    result.img = (a.img * b.real - a.real * b.img) / denominator;
    return result;
}

// Функция для возведения комплексного числа в степень n
Complex power(Complex a, int n) {
    Complex result = a;
    for (int i = 1; i < n; i++) {
        result = multiply(result, a);
    }
    return result;
}

void printComplex(Complex c) {
    if (c.img >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.img);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.img);
    }
}