/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** init_list_cmd
*/

#include <string.h>
#include "minishell2.h"

static void init_info_node(node_info_t *i_node)
{
    i_node->pipe = false;
    i_node->redirection = false;
    i_node->redir.file_in = false;
    i_node->redir.file_out = false;
}

int init_list_cmd(global_t *global)
{
    char *delim_semicolon;
    char *ptr_semicolon;
    int value = 0;
    node_info_t i_node;
    global->l_cmd = NULL;

    delim_semicolon = strtok_r(global->buffer, ";", &ptr_semicolon);

    while (delim_semicolon) {
        init_info_node(&i_node);
        value = check_command(global, delim_semicolon, &i_node);
        switch (value) {
            case 0: i_node.t_cmd = my_str_to_word_array(delim_semicolon, DELIM);
            case 1: break;
            default: return 84;
        }
        add_back_list_cmd(global, &i_node);
        delim_semicolon = strtok_r(NULL, ";", &ptr_semicolon);
    }
    return 0;
}
