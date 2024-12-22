#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value);
void insertSorted(Node** head, int value);
void printList(Node* head);
void freeList(Node* head);
void mergeLists(Node** l1, Node* l2);
void generateSortedRandomList(Node** list, int size);

#endif //LIST_H
