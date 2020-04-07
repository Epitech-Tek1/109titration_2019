/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** init_value
*/

#include "titration.h"

static bool init_data(double **data, char **content,
const size_t nline)
{
    if (!(data = malloc(sizeof(double *) * (nline + 1)))) return (false);
    for (int i = 0; nline > i; i++) {
        if (!(data[i] = malloc(sizeof(double) * 2))) return (false);
        data[i][1] = data[i][0] = atof(_strncpy(content[i], ';'));
    }
    return (true);
}

bool init_value(value_t *value, char const *restrict *restrict av)
{
    stat_t *statf = _stat(av[1], DEFAULT, complet);

    if (!statf || !(value = malloc(sizeof(value_t)))) return (false);
    value->line = statf->nline;
    if (!check_input_file_validity(statf->content)) return (false);
    if (!init_data(value->data, statf->content, statf->nline)) return (false);
    return (true);
}