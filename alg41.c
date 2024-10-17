#include <stdio.h>
#include <string.h>

int numberOfDigits(const int num) {
    int n = num;
    int count = 0;
    do {
        n /= 10;
        ++count;
    } while (n != 0);
    return count;
}

int main(void) {
    int num;
    printf("Введите целое число x: ");
    scanf("%d",&num);

    if(numberOfDigits(num) != 3) {
        printf("Число не трехзначное!");
    } else {
        char arr[4];
        sprintf(arr, "%d", num);

        printf("Число N:\n");

        for (int i = sizeof(arr) - 2; i >= 0; i--) {
            printf("%c\n", arr[i]);
        }
    }

    return 0;
}
