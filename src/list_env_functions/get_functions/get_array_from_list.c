/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** getarray_from_list
*/

#include "minishell2.h"

void get_array_from_list(global_t *global)
{
    int len_env = len_list_env(global->l_env);
    char **new_array = malloc(sizeof(char *) * (len_env + 1));

    list_env_t *tmp = global->l_env;

    for (int i = 0; tmp; i++) {
        new_array[i] = my_strdup(tmp->str);
        tmp = tmp->next;
    }
    new_array[len_env] = NULL;

    free_array(global->env);

    global->env = new_array;
    if (isatty(STDIN_FILENO))
        get_str_prompt(global);
}
