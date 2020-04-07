/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** strnlen
*/

#include "string.h"

size_t _strnlen(const char *restrict string, const char end)
{
    size_t i = 0;

    for (size_t n = 0; string[n]; n++)
        if (end == string[i]) break;
    return (i);
}