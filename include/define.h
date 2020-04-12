/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define EXIT_ERROR 84
#define DESCRIBE "data/describe.txt"

/*          process             */
#define DATA_RESULT (value->data[n + 1][1] - value->data[n - 1][1]) / \
(value->data[n + 1][0] - value->data[n - 1][0])

#endif /* !DEFINE_H_ */