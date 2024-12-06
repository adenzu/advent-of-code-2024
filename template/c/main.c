#include <stdio.h>
#include <string.h>

int part1() { return 0; }

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
