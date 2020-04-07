/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** isdigit
*/

#include "maths.h"

bool _isalpha_digit(const char c)
{
    return ('9' < c || '0' > c) ? (false) : (true);
}