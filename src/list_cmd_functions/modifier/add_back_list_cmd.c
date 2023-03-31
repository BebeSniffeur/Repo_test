/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** add_back_list_cmd
*/

#include "minishell2.h"

void fill_node_list_cmd(list_cmd_t *node, node_info_t *i_node)
{
    node->t_cmd = i_node->t_cmd;
    node->redirection = i_node->redirection;
    node->pipe = i_node->pipe;
    node->redir = i_node->redir;
    node->tree_cmd = i_node->list_tree;
}

void add_back_list_cmd(global_t *global, node_info_t *i_node)
{
    list_cmd_t *tmp = global->l_cmd;
    if (global->l_cmd == NULL) {
        global->l_cmd = malloc(sizeof(list_cmd_t));
        fill_node_list_cmd(global->l_cmd, i_node);
        global->l_cmd->next = NULL;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(list_cmd_t));
    fill_node_list_cmd(tmp->next, i_node);
    tmp->next->next = NULL;
}
