#include <stdlib.h>
#include "util.h"

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList *list, int data)
{
    Node *node = createNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void deleteLinkedList(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int *toArray(LinkedList *list)
{
    int *array = (int *)malloc(list->size * sizeof(int));
    Node *current = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        array[i] = current->data;
        current = current->next;
    }
    return array;
}

void sort(int *array, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
