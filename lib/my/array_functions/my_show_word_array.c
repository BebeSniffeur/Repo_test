/*
** EPITECH PROJECT, 2022
** Pool-Day8
** File description:
** my_show_word_array
*/

#include <stddef.h>
#include "../my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
    return 0;
}
