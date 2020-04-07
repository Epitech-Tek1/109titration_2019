/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** fread
*/

#include "stat.h"

void _fread(const char *restrict filepath)
{
    stat_t *statf = _stat(filepath, DEFAULT, complet);

    for (int i = 0; statf->content[i]; i++) _putstr(statf->content[i], 1);
    _stat_free(statf);
}