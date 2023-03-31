/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** setenv
*/

#include "minishell2.h"

void set_env(global_t *global, list_cmd_t *l_cmd)
{
    char *new_name;
    char *var;

    if (len_array(l_cmd->t_cmd) > 3) {
        my_puterror("setenv: Too many arguments.\n");
        global->cmd_return = 1;
        return;
    }
    if (my_str_isalphanum(l_cmd->t_cmd[1]) == 0) {
        my_puterror("setenv: Variable name must "
        "contain alphanumeric characters.\n");
        global->cmd_return = 1;
        return;
    }
    var = l_cmd->t_cmd[2] ? l_cmd->t_cmd[2] : "";
    new_name = my_strcat(l_cmd->t_cmd[1], "=");
    change_var_list(global, new_name, var, ADD);
    free(new_name);
    get_array_from_list(global);
}
