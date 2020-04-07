/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** init_value
*/

#include "titration.h"

bool init_value(value_t *value, char const *restrict *restrict av)
{
    stat_t *statf = _stat(av[1], DEFAULT, complet);

    if (!statf || !(value = malloc(sizeof(value_t)))) return (false);
    value->line = statf->nline;
    if (!check_input_file_validity(statf->content))
    return (true);
}