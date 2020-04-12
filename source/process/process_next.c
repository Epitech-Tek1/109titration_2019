/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** process_next
*/

#include "titration.h"

bool process_next_third(value_t *value)
{
    double tmp;

    for (int i = 0; value->tmp2 != i; i++)
        printf("%g ml -> %.2f\n", value->deriv[2].deriv_data[i][0], value->deriv[2].deriv_data[i][1]);
    for (int i = 0; i != value->tmp2; i++)
        if (value->deriv[2].deriv_data[i][1] * value->deriv[2].deriv_data[i + 1][1] < 0) {
            tmp = value->deriv[2].deriv_data[i][0];
            break;
        }
    printf("\nEquivalence point at %g ml\n", tmp);
    return (true);
}

bool process_next_second(value_t *value)
{
    int i = 0;

    _putstr("Second derivative:\n", 1);
    for (i = 0; value->line - 4 > i; i++)
        printf("%g ml -> %.2f\n", value->deriv[1].deriv_data[i][0], value->deriv[1].deriv_data[i][1]);
    printf("\nSecond derivative estimated:\n");
    for (i = 0; value->tmp != value->deriv[1].deriv_data[i][0]; i++);
    value->tmp2 = (value->deriv[1].deriv_data[i + 1][0] - value->deriv[1].deriv_data[i - 1][0]) * 10 + 1;
    value->i = i;
    return (true);
}

bool process_next_first(value_t *value)
{
    double tmp = 0;

    value->tmp = value->deriv[0].deriv_data[0][1];
    _putstr("Derivative:\n", 1);
    for (int i = 0; value->line - 2 > i; i++)
        printf("%g ml -> %.2f\n", value->deriv[0].deriv_data[i][0],
        value->deriv[0].deriv_data[i][1]);
    for (int i = 1, n = i; value->line - 2 > i; i++, n = i)
        if (value->deriv[0].deriv_data[i][1] > value->tmp) {
            value->tmp = value->deriv[0].deriv_data[n][1];
            tmp = value->deriv[0].deriv_data[n][0];
        }
    value->tmp = tmp;
    printf("\nEquivalence point at %g ml\n\n", tmp);
    return (true);
}