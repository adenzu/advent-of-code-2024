#include <stdio.h>
#include <string.h>

#define INPUT_WIDTH 140
#define INPUT_HEIGHT 140

char input[INPUT_HEIGHT][INPUT_WIDTH];

int load_input()
{
    static const char filename[] = "../input.txt";

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    for (int i = 0; i < INPUT_HEIGHT; i++)
    {
        for (int j = 0; j < INPUT_WIDTH; j++)
        {
            input[i][j] = fgetc(file);
        }
        input[i][INPUT_WIDTH] = '\0';
        while (fgetc(file) == '\n')
            ;
        fseek(file, -1, SEEK_CUR);
    }

    fclose(file);
    return 0;
}

int find_directed(const char *needle, int y, int x, int dy, int dx)
{
    if (*needle == '\0')
    {
        return 1;
    }

    if (y < 0 || y >= INPUT_HEIGHT || x < 0 || x >= INPUT_WIDTH)
    {
        return 0;
    }

    if (input[y][x] != *needle)
    {
        return 0;
    }

    return find_directed(needle + 1, y + dy, x + dx, dy, dx);
}

int find(const char *needle, int y, int x)
{
    if (*needle == '\0')
    {
        return 1;
    }

    if (y < 0 || y >= INPUT_HEIGHT || x < 0 || x >= INPUT_WIDTH)
    {
        return 0;
    }

    if (input[y][x] != *needle)
    {
        return 0;
    }

    return find_directed(needle + 1, y, x + 1, 0, 1) +
           find_directed(needle + 1, y, x - 1, 0, -1) +
           find_directed(needle + 1, y + 1, x, 1, 0) +
           find_directed(needle + 1, y - 1, x, -1, 0) +
           find_directed(needle + 1, y + 1, x + 1, 1, 1) +
           find_directed(needle + 1, y + 1, x - 1, 1, -1) +
           find_directed(needle + 1, y - 1, x + 1, -1, 1) +
           find_directed(needle + 1, y - 1, x - 1, -1, -1);
}

int part1()
{
    load_input();

    int result = 0;

    char *needle = "XMAS";
    for (int i = 0; i < INPUT_HEIGHT; i++)
    {
        for (int j = 0; j < INPUT_WIDTH; j++)
        {
            if (find(needle, i, j))
            {
                result++;
            }
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
