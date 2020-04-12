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
    process_next_first,
    second_derivation,
    process_next_second,
    third_derivation,
    process_next_third
};

bool process(value_t *value)
{
    double tmp = 0;

    if (!(value->deriv = malloc(sizeof(derivation_t) * 4))) return (false);
    for (int i = 0; process_fct[i]; i++)
        if (!process_fct[i](value)) return (false);
    for (int i = 0; 1 != i; i++)
        if (value->deriv[2].deriv_data[i][1] * value->deriv[2].deriv_data[i + 1][1] < 0) break;
    return (true);
}