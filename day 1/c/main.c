#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

int main()
{
    FILE *file = fopen("../input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    LinkedList *list1 = createLinkedList();
    LinkedList *list2 = createLinkedList();

    int num1, num2;
    while (fscanf(file, "%d %d", &num1, &num2) != EOF)
    {
        addNode(list1, num1);
        addNode(list2, num2);
    }
    fclose(file);

    int *array1 = toArray(list1);
    int *array2 = toArray(list2);

    sort(array1, list1->size);
    sort(array2, list2->size);

    int sum = 0;
    for (size_t i = 0; i < list1->size; i++)
    {
        sum += abs(array1[i] - array2[i]);
    }

    printf("Result: %d\n", sum);

    free(array1);
    free(array2);
    deleteLinkedList(list1);
    deleteLinkedList(list2);

    return 0;
}