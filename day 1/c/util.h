#ifndef MY_UTIL_H
#define MY_UTIL_H

#include <stddef.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

Node *createNode(int data);
LinkedList *createLinkedList();
void addNode(LinkedList *list, int data);
void deleteLinkedList(LinkedList *list);
int *toArray(LinkedList *list);

void sort(int *array, size_t size);

#endif // MY_UTIL_H