#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define sign(x) (x > 0 ? 1 : -1)

#define MAX_REPORT_LENGTH 10
#define MAX_LINE_LENGTH 256

void get_changes(int *report, int report_length, int *changes)
{
    for (int i = 1; i < report_length; i++)
    {
        changes[i - 1] = report[i] - report[i - 1];
    }
}

int has_zero(int *report, int report_length)
{
    for (int i = 0; i < report_length; i++)
    {
        if (report[i] == 0)
        {
            return 1;
        }
    }

    return 0;
}

int all_same_sign(int *report, int report_length)
{
    int s = sign(report[0]);
    for (int i = 1; i < report_length; i++)
    {
        if (sign(report[i]) != s)
        {
            return 0;
        }
    }

    return 1;
}

int *all_abs(int *report, int report_length)
{
    for (int i = 0; i < report_length; i++)
    {
        report[i] = abs(report[i]);
    }

    return report;
}

int all_in_range(int *report, int report_length, int min, int max)
{
    for (int i = 0; i < report_length; i++)
    {
        if (report[i] < min || report[i] > max)
        {
            return 0;
        }
    }

    return 1;
}

void report_without(int *report, int report_length, int index, int *result)
{
    for (int i = 0; i < report_length; i++)
    {
        if (i < index)
        {
            result[i] = report[i];
        }
        else if (i > index)
        {
            result[i - 1] = report[i];
        }
    }
}

int part1()
{
    FILE *file = fopen("../input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    int result = 0;

    int report[MAX_REPORT_LENGTH];
    int change[MAX_REPORT_LENGTH];
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        int length = strlen(line);
        if (line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }

        int report_length = 0;
        int num;
        char *ptr = line;
        while (*ptr != '\0')
        {
            num = strtol(ptr, &ptr, 10);
            report[report_length] = num;
            report_length++;
        }

        get_changes(report, report_length, change);
        int changes_length = report_length - 1;

        if (
            !has_zero(change, changes_length) &&
            all_same_sign(change, changes_length) &&
            all_in_range(all_abs(change, changes_length), changes_length, 1, 3))
        {
            result++;
        }
    }

    fclose(file);
    return result;
}

int part2()
{
    FILE *file = fopen("../input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    int result = 0;

    int report[MAX_REPORT_LENGTH];
    int change[MAX_REPORT_LENGTH];
    int without[MAX_REPORT_LENGTH];
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        int length = strlen(line);
        if (line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }

        int report_length = 0;
        int num;
        char *ptr = line;
        while (*ptr != '\0')
        {
            num = strtol(ptr, &ptr, 10);
            report[report_length] = num;
            report_length++;
        }

        for (int i = 0; i < report_length; i++)
        {
            report_without(report, report_length, i, without);
            get_changes(without, report_length - 1, change);
            int changes_length = report_length - 2;

            if (
                !has_zero(change, changes_length) &&
                all_same_sign(change, changes_length) &&
                all_in_range(all_abs(change, changes_length), changes_length, 1, 3))
            {
                result++;
                break;
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