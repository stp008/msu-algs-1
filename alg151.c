#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    Node* l1 = NULL;
    Node* l2 = NULL;

    int size1, size2;
    printf("Введите размер первого списка: ");
    scanf("%d", &size1);
    printf("Введите размер второго списка: ");
    scanf("%d", &size2);

    // Заполняем списки случайными числами
    generateSortedRandomList(&l1, size1);
    generateSortedRandomList(&l2, size2);

    // Печатаем исходные списки
    printf("Список L1: ");
    printList(l1);
    printf("Список L2: ");
    printList(l2);

    // Объединяем списки
    mergeLists(&l1, l2);

    // Печатаем результат
    printf("Объединённый список L1: ");
    printList(l1);

    // Освобождаем память
    freeList(l1);
    freeList(l2);

    return 0;
}
