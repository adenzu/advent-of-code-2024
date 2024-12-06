#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

#define MAP_SIZE 130
#define GUARD '^'
#define WALL '#'
#define SPACE '.'
#define VISITED 'X'

char map[MAP_SIZE][MAP_SIZE];
int guard_x = -1,
    guard_y = -1;

void load_input()
{
    FILE *file = fopen("../input.txt", "r");

    int x = 0,
        y = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            y++;
            x = 0;
            continue;
        }
        else if (c == GUARD)
        {
            guard_x = x;
            guard_y = y;
        }
        map[y][x] = c;
        x++;
    }

    fclose(file);
}

void print_map()
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int part1()
{
    load_input();

    int result = 1;

    int x = guard_x,
        y = guard_y;
    while (1)
    {
        while (0 <= y - 1 && map[y - 1][x] != WALL)
        {
            if (map[y - 1][x] == SPACE)
            {
                result++;
            }
            map[y - 1][x] = GUARD;
            map[y][x] = VISITED;
            y--;
        }
        if (y == 0)
        {
            break;
        }

        while (x + 1 < MAP_SIZE && map[y][x + 1] != WALL)
        {
            if (map[y][x + 1] == SPACE)
            {
                result++;
            }
            map[y][x + 1] = GUARD;
            map[y][x] = VISITED;
            x++;
        }
        if (x == MAP_SIZE - 1)
        {
            break;
        }

        while (y + 1 < MAP_SIZE && map[y + 1][x] != WALL)
        {
            if (map[y + 1][x] == SPACE)
            {
                result++;
            }
            map[y + 1][x] = GUARD;
            map[y][x] = VISITED;
            y++;
        }
        if (y == MAP_SIZE - 1)
        {
            break;
        }

        while (0 <= x - 1 && map[y][x - 1] != WALL)
        {
            if (map[y][x - 1] == SPACE)
            {
                result++;
            }
            map[y][x - 1] = GUARD;
            map[y][x] = VISITED;
            x--;
        }
        if (x == 0)
        {
            break;
        }
    }

    return result;
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
