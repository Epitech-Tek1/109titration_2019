/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct derivation_s
{
    double **deriv_data;
} derivation_t;

typedef struct value_s
{
    double **data;
    derivation_t *deriv;
    int line;
} value_t;

#endif /* !STRUCT_H_ */