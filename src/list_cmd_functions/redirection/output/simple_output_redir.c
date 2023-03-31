/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** simple_output_redir
*/

#include "minishell2.h"

static void fill_node_redir(node_info_t *i_node, list_str_redir_t *tmp)
{
    i_node->redirection = true;
    i_node->redir.file_out = true;
    i_node->redir.name_file_out = my_strdup(tmp->next->str);
    i_node->redir.mode = OPEN_MODE + O_TRUNC;
    i_node->redir.perm = PERM_CREATE_FILE;
}

void simple_output_redir(global_t *global, node_info_t *i_node)
{
    list_str_redir_t *tmp = global->l_redir;

    while (tmp) {
        if (tmp->str[0] == '>' && tmp->str[1] == '\0') {
            fill_node_redir(i_node, tmp);
            remove_node_list_redir(global, tmp->next);
            remove_node_list_redir(global, tmp);
            return;
        }
        if (tmp->str[0] == '>' && my_strlen(tmp->str) > 1) {
            fill_node_redir(i_node, tmp);
            remove_node_list_redir(global, tmp);
            return;
        }
        tmp = tmp->next;
    }
}
