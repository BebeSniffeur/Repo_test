/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** free_list
*/

#include "minishell2.h"

void free_list(list_env_t *list)
{
    if (list->next)
        free_list(list->next);
    free(list->str);
    free(list);
}
