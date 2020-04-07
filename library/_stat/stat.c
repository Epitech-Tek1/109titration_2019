/*
** EPITECH PROJECT, 2020
** library [WSL: Debian]
** File description:
** _stat
*/

#include "stat.h"

static char *get_name(const char *restrict filepath)
{
    char *name = NULL;
    int begin_name = 0;

    for (begin_name = _strlen((char *)filepath); PREG_MATCH; begin_name--);
    name = _memalloc(_strlen((char *)filepath) - begin_name);
    for (int i = 0; filepath[begin_name]; i++, begin_name++)
        name[i] = filepath[begin_name];
    return (name);
}

static bool count_length(stat_t *statf)
{
    int stdout = 0;

    if (!(statf->length = malloc(sizeof(int) * (statf->nline + 1))))
        return (false);
    statf->length[statf->nline + 1] = '\0';
    if (!(FINFO.stream = _fopen(statf->filepath))) return (false);
    for (int i = 0; true; i++) {
        stdout = getline(&FINFO.lineptr, &FINFO.nread, FINFO.stream);
        if (-1 == stdout) break;
        statf->length[i] = stdout;
    }
    return (true);
}

static bool count_line(stat_t *statf)
{
    if (!(FINFO.stream = _fopen(statf->filepath))) return (false);
    while (-1 != getline(&FINFO.lineptr, &FINFO.nread, FINFO.stream))
        ++statf->nline;
    return (fclose(FINFO.stream) == EXIT_SUCCESS) ? (true) : (false);
}

static bool fill_info(stat_t *statf, type info)
{
    if (!count_line(statf)) return (false);
    if (!count_length(statf)) return (false);
    if (!(FINFO.stream = _fopen(statf->filepath))) return (false);
    if (partial == info) {
        if (!(statf->name = get_name(statf->filepath))) return (false);
        return (fclose(FINFO.stream) == EXIT_SUCCESS) ? (true) : (false);
    }
    statf->content = malloc(S_ARRAY * (statf->nline + 1));
    statf->content[statf->nline] = NULL;
    for (int i = 0; statf->nline != i; i++) {
        if (!(statf->content[i] = _memalloc(statf->length[i])))
            return (false);
        getline(&statf->content[i], &FINFO.nread, FINFO.stream);
    }
    if (!(statf->name = get_name(statf->filepath))) return (false);
    return (fclose(FINFO.stream) == EXIT_SUCCESS) ? (true) : (false);
}

stat_t *_stat(const char *restrict filepath, size_t nread, type info)
{
    stat_t *statf = NULL;

    statf = _init_stat(statf, filepath, nread, info);
    if (!fill_info(statf, info)) return (NULL);
    return (statf);
}