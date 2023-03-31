/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_command
*/

#include "minishell2.h"

int check_command(global_t *global, char *cmd, node_info_t *i_node)
{
    if (char_in_str('>', cmd) || char_in_str('<', cmd)) {
        if (do_redirection(global, cmd, i_node))
            return 84;
        return 1;
    }
    return 0;
}
