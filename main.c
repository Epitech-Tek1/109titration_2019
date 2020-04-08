/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** main
*/

#include "titration.h"

static bool titration(const int ac, char const *restrict *restrict av)
{
    value_t *value = NULL;

    if (ac != 2) return (false);
    if (IS_DESCRIBE) return (!_fread(DESCRIBE)) ? (false) : (true);
    if (!init_value(value, av)) return (false);
    if (!process(value)) return (false);
    return (true);
}

int main(const int ac, char const *restrict *restrict av)
{
    return (titration(ac, av)) ? (EXIT_SUCCESS) : (EXIT_ERROR);
}