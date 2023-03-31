/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** check_builtins
*/

#include "minishell2.h"

static int check_print_or_exit(global_t *global, list_cmd_t *l_cmd)
{
    if (my_strcmp(l_cmd->t_cmd[0], "exit") == 0) {
        free_array(l_cmd->t_cmd);
        free_list_cmd(global->l_cmd);
        free_prog(global);
        exit(0);
    }
    if (my_strcmp(l_cmd->t_cmd[0], "env") == 0) {
        if (len_array(l_cmd->t_cmd) > 1) {
            my_putstr("env: Too many args.");
            global->cmd_return = 1;
            return 1;
        }
        my_show_word_array(global->env);
        return 1;
    }
    return 0;
}

int check_builtins(global_t *global, list_cmd_t *l_cmd)
{
    if (check_print_or_exit(global, l_cmd))
        return 1;

    if (my_strcmp(l_cmd->t_cmd[0], "cd") == 0) {
        change_dir(global, l_cmd);
        return 1;
    }
    if (my_strcmp(l_cmd->t_cmd[0], "setenv") == 0) {
        if (len_array(l_cmd->t_cmd) == 1) {
            my_show_word_array(global->env);
            return 1;
        }
        set_env(global, l_cmd);
        return 1;
    }
    if (my_strcmp(l_cmd->t_cmd[0], "unsetenv") == 0) {
        unset_env(global, l_cmd);
        return 1;
    }
    return 0;
}
