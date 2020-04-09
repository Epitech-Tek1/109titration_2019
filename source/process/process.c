/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** process
*/

#include "titration.h"

static bool (*process_fct[])(value_t *) =
{
    first_derivation,
    second_derivation
};

bool process(value_t *value)
{
    for (int i = 0; process_fct[i]; i++)
        if (!process_fct[i](value)) return (false);
    return (true);
}