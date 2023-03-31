/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** remove_var_list
*/

#include "minishell2.h"

void remove_var_list(list_env_t *list)
{
    if (list->next == NULL) {
        list->prev->next = NULL;
        free(list->str);
        free(list);
        return;
    }
    list->prev->next = list->next;
    list->next->prev = list->prev;
    free(list->str);
    free(list);
}
