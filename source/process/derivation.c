/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** derivation
*/

#include "titration.h"

bool third_derivation(value_t *value)
{
    double tmp = value->deriv[1].deriv_data[value->i - 1][0];
    double data = 0;
    double n = 0;
    int i = 0;

    if (!(value->deriv[2].deriv_data = malloc(sizeof(double *) * value->tmp2)))
        return (false);
    for (int i = 0; value->tmp2 != i; i++) {
        if (!(value->deriv[2].deriv_data[i] = malloc(sizeof(double) * 2)))
            return (false);
        value->deriv[2].deriv_data[i][0] = tmp;
        tmp += 0.1;
    }
    data = (value->deriv[1].deriv_data[value->i][1] - value->deriv[1].deriv_data[value->i - 1][1]) / ((value->deriv[1].deriv_data[value->i][0] - value->deriv[1].deriv_data[value->i - 1][0]) * 10);
    value->deriv[2].deriv_data[0][1] = value->deriv[1].deriv_data[value->i - 1][1];
    n = value->deriv[2].deriv_data[0][0];
    for (i = 1; value->deriv[1].deriv_data[value->i][0] - 0.1 > n; i++, n += 0.1)
        value->deriv[2].deriv_data[i][1] = value->deriv[2].deriv_data[i - 1][1] + data;
    data = (value->deriv[1].deriv_data[value->i + 1][1] - value->deriv[1].deriv_data[value->i][1]) / ((value->deriv[1].deriv_data[value->i + 1][0] - value->deriv[1].deriv_data[value->i][0]) * 10);
    for (; value->deriv[1].deriv_data[value->i + 1][0] - 0.1 > n; i++, n += 0.1)
        value->deriv[2].deriv_data[i][1] = value->deriv[2].deriv_data[i - 1][1] + data;
    return (true);
}

bool second_derivation(value_t *value)
{
    if (!(value->deriv[1].deriv_data = malloc(sizeof(double *) *
    (value->line - 3))))
        return (false);
    for (int i = 0, n = 1; (value->line - 4) > i; i++, n++) {
        if (!(value->deriv[1].deriv_data[i] = malloc(sizeof(double) * 2)))
            return (false);
        value->deriv[1].deriv_data[i][0] = value->deriv[0].deriv_data[n][0];
        value->deriv[1].deriv_data[i][1] = (value->deriv[0].deriv_data[n + 1][1] - value->deriv[0].deriv_data[n - 1][1]) / (value->deriv[0].deriv_data[n + 1][0] - value->deriv[0].deriv_data[n - 1][0]);
    }
    return (true);
}

bool first_derivation(value_t *value)
{
    if (!(value->deriv[0].deriv_data = malloc(sizeof(double *) * (value->line - 1))))
        return (false);
    for (int i = 0, n = 1; (value->line - 2) > i; i++, n++) {
        if (!(value->deriv[0].deriv_data[i] = malloc(sizeof(double) * 2)))
            return (false);
        value->deriv[0].deriv_data[i][0] = value->data[n][0];
        value->deriv[0].deriv_data[i][1] = (DATA_RESULT);
    }
    return (true);
}