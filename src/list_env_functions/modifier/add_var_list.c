/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** add_var_list
*/

#include "minishell2.h"

void add_var_list(global_t *global, char *name_var, char *text_var)
{
    char *new_env = my_strcat(name_var, text_var);

    add_back_list_env(global, new_env);
    free(new_env);
}
