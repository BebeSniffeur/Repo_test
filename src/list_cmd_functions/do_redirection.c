/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_redirection
*/

#include "minishell2.h"

int do_redirection(global_t *global, char *cmd, node_info_t *i_node)
{
    int count_output = count_char_in_str(cmd, '>');
    int count_input = count_char_in_str(cmd, '<');

    if (check_redirection_error(global, count_input, count_output, cmd))
        return 84;
    get_list_array_redir(global, cmd);
    switch (count_input) {
        case 1: simple_input_redir(global, i_node); break;
        case 2: double_input_redir(global, i_node); break;
        default: break;
    }
    switch (count_output) {
        case 1: simple_output_redir(global, i_node); break;
        case 2: double_output_redir(global, i_node); break;
        default: break;
    }
    i_node->t_cmd = get_array_from_list_redir(global);
    return 0;
}
