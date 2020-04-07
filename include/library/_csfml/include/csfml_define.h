/*
** EPITECH PROJECT, 2020
** csfml [WSL: Debian]
** File description:
** csfml_define
*/

#ifndef CSFML_DEFINE_H_
#define CSFML_DEFINE_H_

#define EXIT_ERROR 84

/*          init_csfml          */
#define CPY_MATCH '=', '\n'
#define ISTRNLCPY(src) (_atoi(_strnlcpy(src, CPY_MATCH)))
#define SSTRNLCPY(src) (_stricpy(_strnlcpy(src, CPY_MATCH), '\n'))

#endif /* !CSFML_DEFINE_H_ */