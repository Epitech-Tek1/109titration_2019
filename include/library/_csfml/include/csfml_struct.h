/*
** EPITECH PROJECT, 2020
** csfml [WSL: Debian]
** File description:
** csfml_struct
*/

#ifndef CSFML_STRUCT_H_
#define CSFML_STRUCT_H_

typedef struct window_s
{
    sfRenderWindow *window;
    sfEvent event;
    sfImage *icon;
    sfVideoMode viewport;
    char *title;
} window_t;

typedef struct thread_s
{
    sfThread *thread;
} thread_t;


typedef struct csfml_s
{
    window_t window;
    thread_t *thread;
    sfMutex **mutex;
    sfBool exit;
    sfClock **clock;
} csfml_t;


#endif /* !CSFML_STRUCT_H_ */