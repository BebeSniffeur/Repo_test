/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** remove_node_list_redir
*/

#include "minishell2.h"

static void free_node_redir(list_str_redir_t *l_redir)
{
    free(l_redir->str);
    free(l_redir);
}

void remove_node_list_redir(global_t *global, list_str_redir_t *l_redir)
{
    if (l_redir->next == NULL && l_redir->prev == NULL) {
        free_node_redir(l_redir);
        global->l_redir = NULL;
        return;
    }
    if (l_redir->prev == NULL) {
        global->l_redir = global->l_redir->next;
        free_node_redir(l_redir);
        global->l_redir->prev = NULL;
        return;
    }
    if (l_redir->next == NULL) {
        l_redir->prev->next = NULL;
        free_node_redir(l_redir);
        return;
    }
    l_redir->prev->next = l_redir->next;
    l_redir->next->prev = l_redir->prev;
    free_node_redir(l_redir);
}
