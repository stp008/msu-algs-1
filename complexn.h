#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    double real;
    double img;
} Complex;

// Прототипы функций
int compareComplex(Complex a, Complex b, double epsilon);
Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);
Complex power(Complex a, int n);
void printComplex(Complex c);

#endif // COMPLEX_H