/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_error_cd
*/

#include "minishell2.h"

int check_error_cd(global_t *global, list_cmd_t *l_cmd)
{
    char *path = l_cmd->t_cmd[1];
    if (len_array(l_cmd->t_cmd) > 2) {
        my_puterror("cd: Too many arguments.\n");
        global->cmd_return = 1;
        return 1;
    }
    if (len_array(l_cmd->t_cmd) != 1 && !my_strncmp(path, "-", 1)
    && my_strlen (path) > 1) {
        my_puterror("Usage: cd [-~][-|<dir>].\n");
        return 1;
    }
    return 0;
}
