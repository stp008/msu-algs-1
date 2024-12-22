#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// Тест для функции createNode
void test_createNode() {
    Node* node = createNode(42);
    assert(node != NULL);
    assert(node->value == 42);
    assert(node->next == NULL);
    free(node);
    printf("Тест createNode успешно пройден\n");
}

// Тест для функции insertSorted
void test_insertSorted() {
    Node* list = NULL;

    insertSorted(&list, 10);
    insertSorted(&list, 5);
    insertSorted(&list, 20);

    assert(list->value == 5);
    assert(list->next->value == 10);
    assert(list->next->next->value == 20);

    freeList(list);
    printf("Тест insertSorted успешно пройден\n");
}

// Тест для функции mergeLists
void test_mergeLists() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    insertSorted(&l1, 1);
    insertSorted(&l1, 3);
    insertSorted(&l1, 5);

    insertSorted(&l2, 2);
    insertSorted(&l2, 4);
    insertSorted(&l2, 6);

    mergeLists(&l1, l2);

    Node* current = l1;
    for (int i = 1; i <= 6; i++) {
        assert(current != NULL);
        assert(current->value == i);
        current = current->next;
    }

    freeList(l1);
    printf("Тест mergeLists успешно пройден\n");
}

// Тест для функции generateSortedRandomList
void test_generateSortedRandomList() {
    Node* list = NULL;
    generateSortedRandomList(&list, 10);

    Node* current = list;
    int prevValue = 0;
    while (current != NULL) {
        assert(current->value >= prevValue);
        prevValue = current->value;
        current = current->next;
    }

    freeList(list);
    printf("Тест generateSortedRandomList успешно пройден\n");
}

int main() {
    srand(time(NULL));

    test_createNode();
    test_insertSorted();
    test_mergeLists();
    test_generateSortedRandomList();

    printf("Все тесты успешно пройдены!\n");
    return 0;
}
