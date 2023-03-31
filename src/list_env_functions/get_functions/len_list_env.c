/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** len_list
*/

#include "minishell2.h"

int len_list_env(list_env_t *list)
{
    int count = 0;

    list_env_t *tmp = list;
    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
