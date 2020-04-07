/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** error_handling
*/

#include "titration.h"
#undef PREG_MATCH
#define PREG_MATCH content[i][n] && content[i][n] != '\n'

bool check_input_file_validity(char **content)
{
    while (**content)
        if (!_isalpha_number(*content)) return (false);
        else content++;
}