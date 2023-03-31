/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** add_back_list
*/

#include "minishell2.h"

void add_back_list_env(global_t *global, char *env)
{
    list_env_t *tmp = global->l_env;
    if (global->l_env == NULL) {
        global->l_env = malloc(sizeof(list_env_t));
        global->l_env->str = my_strdup(env);
        global->l_env->next = NULL;
        global->l_env->prev = NULL;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(list_env_t));
    tmp->next->str = my_strdup(env);
    tmp->next->prev = tmp;
    tmp->next->next = NULL;
}
