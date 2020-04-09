/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** derivation
*/

#include "titration.h"

bool second_derivation(value_t *value)
{

}

bool first_derivation(value_t *value)
{
    for (int i = 0; value->data[i]; i++)
        printf("%f\n", value->data[i][0]);
    if (!(value->deriv = malloc(sizeof(derivation_t) * 4))) return (false);
    if (!(value->deriv[0].deriv_data = malloc(sizeof(double *) *
    (value->line - 1))))
        return (false);
    for (int i = 0, n = 1; (value->line - 2) > i; i++, n++) {
        if (!(value->deriv[0].deriv_data[i] = malloc(sizeof(double) * 2)))
            return (false);
        value->deriv[0].deriv_data[i][0] = value->data[n][0];
        value->deriv[0].deriv_data[i][1] = (DATA_RESULT);
    }
    return (true);
}