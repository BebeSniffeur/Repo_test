/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** double_output_redir
*/

#include "minishell2.h"

static void fill_node_redir(node_info_t *i_node, char *cmd)
{
    i_node->redirection = true;
    i_node->redir.file_out = true;
    i_node->redir.name_file_out = my_strdup(cmd);
    i_node->redir.mode = OPEN_MODE + O_APPEND;
    i_node->redir.perm = PERM_CREATE_FILE;
}

void double_output_redir(global_t *global, node_info_t *i_node)
{
    list_str_redir_t *tmp = global->l_redir;

    while (tmp) {
        if (!my_strcmp(tmp->str, ">>")) {
            fill_node_redir(i_node, tmp->next->str);
            remove_node_list_redir(global, tmp->next);
            remove_node_list_redir(global, tmp);
            return;
        }
        if (my_strlen(tmp->str) > 2 && !my_strncmp(tmp->str, ">>", 2)) {
            fill_node_redir(i_node, &tmp->str[2]);
            remove_node_list_redir(global, tmp);
            return;
        }
        tmp = tmp->next;
    }
}
