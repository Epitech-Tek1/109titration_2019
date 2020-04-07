/*
** EPITECH PROJECT, 2020
** library [WSL: Debian]
** File description:
** _stat
*/

#include "stat.h"

static stat_t *init_stat(stat_t *statf, const char *filepath, size_t nread,
type info)
{
    statf = malloc(sizeof(stat_t));
    FINFO.lineptr = NULL;
    FINFO.stream = NULL;
    FINFO.nline = 0;
    FINFO.nread = nread;
    FINFO.info = info;
    statf->content = NULL;
    statf->filepath = _strdup(filepath);
    statf->name = NULL;
    statf->nline = 0;
    return (statf);
}

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

static bool count_line(stat_t *statf)
{
    if (!(FINFO.stream = _fopen(statf->filepath))) return (false);
    while (-1 != getline(&FINFO.lineptr, &FINFO.nread, FINFO.stream))
        ++statf->nline;
    return (fclose(FINFO.stream) == EXIT_SUCCESS) ? (true) : (false);
}

static bool fill_info(stat_t *statf, type info)
{
    count_line(statf);
    if (!(FINFO.stream = _fopen(statf->filepath))) return (false);
    if (complet == info) {
        statf->content = malloc(S_ARRAY * (statf->nline + 1));
        statf->content[statf->nline] = NULL;
        for (int i = 0; statf->nline != i; i++) {
            statf->content[i] = _memalloc(100);
            getline(&statf->content[i], &FINFO.nread, FINFO.stream);
        }
    }
    statf->name = get_name(statf->filepath);
    return (fclose(FINFO.stream) == EXIT_SUCCESS) ? (true) : (false);
}

stat_t *_stat(const char *restrict filepath, size_t nread, type info)
{
    stat_t *statf = NULL;

    statf = init_stat(statf, filepath, nread, info);
    if (!fill_info(statf, info)) return (NULL);
    return (statf);
}