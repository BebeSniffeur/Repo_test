/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** simple_redir_input
*/

#include "minishell2.h"

void simple_input_redir(global_t *global, node_info_t *i_node)
{
    list_str_redir_t *tmp = global->l_redir;

    while (tmp) {
        if (tmp->str[0] == '<' && tmp->str[1] == '\0') {
            i_node->redirection = true;
            i_node->redir.file_in = true;
            i_node->redir.name_file_in = my_strdup(tmp->next->str);
            remove_node_list_redir(global, tmp->next);
            remove_node_list_redir(global, tmp);
            return;
        }
        if (tmp->str[0] == '<' && my_strlen(tmp->str) > 1) {
            i_node->redirection = true;
            i_node->redir.file_in = true;
            i_node->redir.name_file_in = my_strdup(&tmp->str[1]);
            remove_node_list_redir(global, tmp);
            return;
        }
        tmp = tmp->next;
    }
}
