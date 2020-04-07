/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** isalpha_number
*/

#include "maths.h"

bool _isalpha_number(const char *restrict string)
{
    while (*string)
        if (!_isalpha_digit(*string)) return (false);
        else string++;
    return (true);
}