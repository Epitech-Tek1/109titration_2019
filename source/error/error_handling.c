/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** error_handling
*/

#include "titration.h"

bool check_input_file_validity(char **content, size_t nline)
{
    for (int i = 0; i != nline; i++)
        if (!_preg_match("1234567890.;\n", content[i])) return (false);
    return (true);
}