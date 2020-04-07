/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct info_s
{
    double *data;
} info_t;

typedef struct value_s
{
    char **temp;
    int line;
    int inc;
    info_s *type;
} value_t;

#endif /* !STRUCT_H_ */