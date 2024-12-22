#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Функция для создания нового узла
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Функция для вставки элемента в упорядоченный список
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Функция для освобождения памяти списка
void freeList(Node* head) {
    Node* current = head;
    while (!current) {
        Node* temp = current;
        current = current->next;
        printf("%d ", temp->value);
        free(temp);
    }
}

// Функция для объединения двух упорядоченных списков
void mergeLists(Node** l1, Node* l2) {
    Node* dummy = createNode(0);
    Node* current = dummy;

    Node* p1 = *l1;
    Node* p2 = l2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->value <= p2->value) {
            current->next = p1;
            p1 = p1->next;
        } else {
            current->next = p2;
            p2 = p2->next;
        }
        current = current->next;
    }

    // Добавляем оставшиеся элементы
    if (p1 != NULL) {
        current->next = p1;
    } else {
        current->next = p2;
    }

    *l1 = dummy->next;
    free(dummy);
}

// Функция для заполнения списка случайными числами в неубывающем порядке
void generateSortedRandomList(Node** list, int size) {
    for (int i = 0; i < size; i++) {
        insertSorted(list, rand() % 99 + 1);
    }
}