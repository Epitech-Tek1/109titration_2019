/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** strncpy
*/

#include "string.h"

char *_strncpy(const char *src, const char n)
{
    int length = _strnlen(src, n);
    char *dest = _memalloc(length);

    for (int i = 0; n != src[i]; i++) dest[i] = src[i];
    return (dest);
}