#include <stdio.h>
#include <string.h>

int starts_with(const char *pre, const char *str)
{
    for (int i = 0; pre[i] != '\0'; i++)
    {
        if (pre[i] != str[i])
        {
            return 0;
        }
    }
    return 1;
}

void shift_and_append(char c, char *buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size - 1; i++)
    {
        buffer[i] = buffer[i + 1];
    }
    buffer[buffer_size - 1] = c;
}

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int to_number(char c)
{
    return c - '0';
}

int part1()
{
    static const char *needle = "mul(";

    int result = 0;

    FILE *file = fopen("../input.txt", "r");

    int nums[2] = {0, 0};
    int num_index = 0;
    int is_mul = 0;
    int max_int = 99;

    char buffer[4];
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        shift_and_append(c, buffer, 4);
        if (starts_with(needle, buffer))
        {
            is_mul = 1;
        }
        else if (is_mul)
        {
            if (is_digit(c) && nums[num_index] <= max_int)
            {
                nums[num_index] = nums[num_index] * 10 + to_number(c);
            }
            else if (c == ',' && num_index == 0)
            {
                num_index++;
            }
            else if (c == ')')
            {
                result += nums[0] * nums[1];
                nums[0] = 0;
                nums[1] = 0;
                num_index = 0;
                is_mul = 0;
            }
            else
            {
                nums[0] = 0;
                nums[1] = 0;
                num_index = 0;
                is_mul = 0;
            }
        }
    }

    fclose(file);
    return result;
}

int part2()
{
    static const char *needle = "mul(";

    int result = 0;

    FILE *file = fopen("../input.txt", "r");

    int skip = 0;
    int nums[2] = {0, 0};
    int num_index = 0;
    int is_mul = 0;
    int max_int = 99;

    char bigger_buffer[8];
    char buffer[4];
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        shift_and_append(c, bigger_buffer, 8);
        shift_and_append(c, buffer, 4);

        if (starts_with("do()", bigger_buffer))
        {
            skip = 0;
        }
        else if (starts_with("don't()", bigger_buffer))
        {
            skip = 1;
        }

        if (skip)
        {
            continue;
        }

        else if (starts_with(needle, buffer))
        {
            is_mul = 1;
        }
        else if (is_mul)
        {
            if (is_digit(c) && nums[num_index] <= max_int)
            {
                nums[num_index] = nums[num_index] * 10 + to_number(c);
            }
            else if (c == ',' && num_index == 0)
            {
                num_index++;
            }
            else if (c == ')')
            {
                result += nums[0] * nums[1];
                nums[0] = 0;
                nums[1] = 0;
                num_index = 0;
                is_mul = 0;
            }
            else
            {
                nums[0] = 0;
                nums[1] = 0;
                num_index = 0;
                is_mul = 0;
            }
        }
    }

    fclose(file);
    return result;
}

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
        printf("Invalid part\n");
        return 1;
    }

    return 0;
}