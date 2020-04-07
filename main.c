/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** main
*/

#include "titration.h"

int main(const int ac, char const *restrict *restrict av)
{
    if (ac != 2) return (false);
    if (IS_DESCRIBE) {
        _fread(DESCRIBE);
        return (EXIT_SUCCESS);
    }
    return 0;
}