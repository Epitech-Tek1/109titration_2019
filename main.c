/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** main
*/

#include "titration.h"

int main(int ac, char const *av[])
{
    if (ac == 2 && IS_DESCRIBE) {
        _fread(DESCRIBE);
        return (EXIT_SUCCESS);
    }
    return 0;
}
