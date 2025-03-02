/*
** EPITECH PROJECT, 2020
** 109titration_2019 [WSL: Debian]
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

bool init_value(value_t *value, char const *restrict *restrict av, int *line);

bool check_input_file_validity(char **content, size_t nline);

/*          process             */
bool process(value_t *value);
bool first_derivation(value_t *value);
bool process_next_first(value_t *value);
bool second_derivation(value_t *value);
bool process_next_second(value_t *value);
bool third_derivation(value_t *value);
bool process_next_third(value_t *value);

#endif /* !FUNCTION_H_ */