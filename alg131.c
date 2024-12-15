#include <stdio.h>
#include "complexn.c"

int main() {
    const Complex i = {0, 1}; // Мнимая единица

    // Вычисление результата выражения 0.25*[(17+31i)/(7+i)+12/(1+i)^4]+i
    Complex result = add(
        multiply(divide((Complex){17, 31}, (Complex){7, 1}), (Complex){0.25, 0}),
                         add(divide((Complex){12, 0}, power((Complex){1, 1}, 4)), i));

    // Печатаем итоговый результат
    printf("Результат: ");
    printComplex(result);

    return 0;
}
