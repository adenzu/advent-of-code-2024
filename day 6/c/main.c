#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

#define STRIPE_LENGTH 130

int **vertical_stripes;
int vertical_stripe_lengths[STRIPE_LENGTH];
int vertical_stripe_max_lengths[STRIPE_LENGTH];

int **horizontal_stripes;
int horizontal_stripe_lengths[STRIPE_LENGTH];
int horizontal_stripe_max_lengths[STRIPE_LENGTH];

int guard_x = 0,
    guard_y = 0;

void init_global_variables()
{
    vertical_stripes = (int **)malloc(STRIPE_LENGTH * sizeof(int *));
    horizontal_stripes = (int **)malloc(STRIPE_LENGTH * sizeof(int *));

    printf("Allocated memory for vertical and horizontal stripes\n");

    const int initial_length = 4;
    for (int i = 0; i < STRIPE_LENGTH; i++)
    {
        vertical_stripes[i] = (int *)malloc(initial_length * sizeof(int));
        vertical_stripe_lengths[i] = 0;
        vertical_stripe_max_lengths[i] = initial_length;

        horizontal_stripes[i] = (int *)malloc(initial_length * sizeof(int));
        horizontal_stripe_lengths[i] = 0;
        horizontal_stripe_max_lengths[i] = initial_length;
    }
}

void load_input()
{
    FILE *file = fopen("../input.txt", "r");

    int x = 0,
        y = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        switch (c)
        {
        case '#':
            add(&vertical_stripes[x], y, &vertical_stripe_lengths[x], &vertical_stripe_max_lengths[x]);
            add(&horizontal_stripes[y], x, &horizontal_stripe_lengths[y], &horizontal_stripe_max_lengths[y]);
            break;
        case '.':
            break;
        case '\n':
            y++;
            x = -1;
            break;
        case '^':
            guard_x = x;
            guard_y = y;
            break;
        default:
            printf("Invalid character: %c\n", c);
            break;
        }
        x++;
    }

    for (int i = 0; i < STRIPE_LENGTH; i++)
    {
        sort(vertical_stripes[i], vertical_stripe_lengths[i]);
        sort(horizontal_stripes[i], horizontal_stripe_lengths[i]);
    }

    fclose(file);
}

void find_next_obstacle_up(int x, int y, int *next_x, int *next_y)
{
    for (int i = 0; i < vertical_stripe_lengths[x]; i++)
    {
        if (vertical_stripes[x][i] > y)
        {
            *next_x = x;
            *next_y = vertical_stripes[x][i];
            return;
        }
    }
    *next_x = -1;
    *next_y = -1;
}

void find_next_obstacle_down(int x, int y, int *next_x, int *next_y)
{
    for (int i = vertical_stripe_lengths[x] - 1; i >= 0; i--)
    {
        if (vertical_stripes[x][i] < y)
        {
            *next_x = x;
            *next_y = vertical_stripes[x][i];
            return;
        }
    }
    *next_x = -1;
    *next_y = -1;
}

void find_next_obstacle_right(int x, int y, int *next_x, int *next_y)
{
    for (int i = 0; i < horizontal_stripe_lengths[y]; i++)
    {
        if (horizontal_stripes[y][i] > x)
        {
            *next_x = horizontal_stripes[y][i];
            *next_y = y;
            return;
        }
    }
    *next_x = -1;
    *next_y = -1;
}

void find_next_obstacle_left(int x, int y, int *next_x, int *next_y)
{
    for (int i = horizontal_stripe_lengths[y] - 1; i >= 0; i--)
    {
        if (horizontal_stripes[y][i] < x)
        {
            *next_x = horizontal_stripes[y][i];
            *next_y = y;
            return;
        }
    }
    *next_x = -1;
    *next_y = -1;
}

int part1()
{
    init_global_variables();
    load_input();

    int visited = 1;

    int x = guard_x,
        y = guard_y;

    int next_x = -1,
        next_y = -1;

    while (1)
    {
        visited++;

        find_next_obstacle_down(x, y, &next_x, &next_y);
        if (next_x == -1 && next_y == -1)
        {
            break;
        }
        visited += y - next_y - 1;
        y = next_y + 1;

        find_next_obstacle_right(x, y, &next_x, &next_y);
        if (next_x == -1 && next_y == -1)
        {
            break;
        }
        visited += next_x - x - 1;
        x = next_x - 1;

        find_next_obstacle_up(x, y, &next_x, &next_y);
        if (next_x == -1 && next_y == -1)
        {
            break;
        }
        visited += next_y - y - 1;
        y = next_y - 1;

        find_next_obstacle_left(x, y, &next_x, &next_y);
        if (next_x == -1 && next_y == -1)
        {
            break;
        }
        visited += x - next_x - 1;
        x = next_x - 1;
    }

    return visited;
}

int part2() { return 0; }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <part1|part2>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "part1") == 0)
    {
        printf("%d\n", part1());
    }
    else if (strcmp(argv[1], "part2") == 0)
    {
        printf("%d\n", part2());
    }
    else
    {
        printf("Usage: %s <part1|part2>\n", argv[0]);
        return 1;
    }

    return 0;
}
