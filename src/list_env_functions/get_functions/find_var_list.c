/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** find_var_list
*/

#include "minishell2.h"

list_env_t *find_var_list(list_env_t *list, char *env_var)
{
    list_env_t *tmp = list;
    while (tmp) {
        if (!my_strncmp(tmp->str, env_var, my_strlen(env_var)))
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
