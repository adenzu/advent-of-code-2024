#include <stdlib.h>
#include <string.h>

#include "util.h"

void add(int **array, int value, int *length, int *max_length)
{
    if (length < max_length)
    {
        (*array)[(*length)] = value;
        (*length)++;
    }
    else
    {
        return;
        int new_length = (*max_length) * 2;
        int *new_array = (int *)malloc(new_length * sizeof(int));
        memcpy(new_array, *array, (*length) * sizeof(int));
        free(*array);
        *array = new_array;
        (*array)[(*length)] = value;
        (*length)++;
        *max_length = new_length;
    }
}

void sort(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
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
