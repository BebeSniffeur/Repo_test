/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** change_var_list
*/

#include "minishell2.h"

void change_var_list(global_t *global, char *env_var, char *new_var, bool add)
{
    char *new_str = NULL;
    list_env_t *change_node = NULL;

    if ((change_node = find_var_list(global->l_env, env_var))) {
        free(change_node->str);
        new_str = my_strcat(env_var, new_var);
        change_node->str = new_str;
    } else if (add) {
        add_var_list(global, env_var, new_var);
    }
}
