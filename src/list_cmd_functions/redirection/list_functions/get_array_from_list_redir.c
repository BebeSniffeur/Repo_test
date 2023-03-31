/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** get_array_from_list_redir
*/

#include "minishell2.h"

static int len_list_redir(list_str_redir_t *l_redir)
{
    int count = 0;

    list_str_redir_t *tmp = l_redir;
    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

static void free_list_redir(list_str_redir_t *l_redir)
{
    if (l_redir->next)
        free_list_redir(l_redir->next);
    free(l_redir);
}

char **get_array_from_list_redir(global_t *global)
{
    int len_env = len_list_redir(global->l_redir);
    char **new_array = malloc(sizeof(char *) * (len_env + 1));

    list_str_redir_t *tmp = global->l_redir;

    for (int i = 0; tmp; i++) {
        new_array[i] = tmp->str;
        tmp = tmp->next;
    }
    new_array[len_env] = NULL;
    free_list_redir(global->l_redir);
    global->l_redir = NULL;
    return new_array;
}
