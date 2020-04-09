/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** printt
*/

#include "string.h"

void printt_string(char **array)
{
    for (int i = 0; array[i]; i++)
        _putstr(array[i], 1);
}

void printt_number(int *array)
{
    for (int i = 0; array[i]; i++)
        _putnbr(array[i], 1);
}

void _printt(const char *restrict format, const void *array)
{
    if (_strcmp(format, "%s")) printt_string((char **)array);
    else if (_strcmp(format, "%d")) printt_number((int *)array);
}