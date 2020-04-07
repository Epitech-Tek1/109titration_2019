/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** openf_function
*/

#ifndef OPENF_FUNCTION_H_
#define OPENF_FUNCTION_H_

stat_t *_stat(const char *__restrict__ filepath, size_t nread, type info);
void _stat_free(stat_t *statf);

FILE *_fopen(const char *__restrict__ filepath);

void _fread(const char *__restrict__ filepath);

#endif /* !OPENF_FUNCTION_H_ */