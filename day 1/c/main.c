#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "util.h"

void loadInput(LinkedList *list1, LinkedList *list2)
{
    FILE *file = fopen("../input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int num1, num2;
    while (fscanf(file, "%d %d", &num1, &num2) != EOF)
    {
        addNode(list1, num1);
        addNode(list2, num2);
    }
    fclose(file);
}

int part1()
{
    LinkedList *list1 = createLinkedList();
    LinkedList *list2 = createLinkedList();

    loadInput(list1, list2);

    int *array1 = toArray(list1);
    int *array2 = toArray(list2);

    sort(array1, list1->size);
    sort(array2, list2->size);

    int sum = 0;
    for (size_t i = 0; i < list1->size; i++)
    {
        sum += abs(array1[i] - array2[i]);
    }

    free(array1);
    free(array2);
    deleteLinkedList(list1);
    deleteLinkedList(list2);

    return sum;
}

int part2()
{
    LinkedList *list1 = createLinkedList();
    LinkedList *list2 = createLinkedList();

    loadInput(list1, list2);

    int *array1 = toArray(list1);
    int *array2 = toArray(list2);

    sort(array1, list1->size);
    sort(array2, list2->size);

    int sum = 0;
    for (size_t i = 0, j = 0; i < list1->size && j < list2->size;)
    {
        if (array1[i] == array2[j])
        {
            sum += array1[i];
            j++;
        }
        else if (array1[i] < array2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    free(array1);
    free(array2);
    deleteLinkedList(list1);
    deleteLinkedList(list2);

    return sum;
}

// Argument needed for selecting part1 or part2
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <part1|part2>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "part1") == 0)
    {
        printf("Part 1: %d\n", part1());
    }
    else if (strcmp(argv[1], "part2") == 0)
    {
        printf("Part 2: %d\n", part2());
    }
    else
    {
        printf("Invalid argument: %s\n", argv[1]);
        return 1;
    }

    return 0;
}