/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** get_array_frome_list_redir
*/

#include "minishell2.h"

static void add_back_list_redir(global_t *global, char *str)
{
    list_str_redir_t *tmp = global->l_redir;
    if (global->l_redir == NULL) {
        global->l_redir = malloc(sizeof(list_str_redir_t));
        global->l_redir->str = str;
        global->l_redir->next = NULL;
        global->l_redir->prev = NULL;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(list_str_redir_t));
    tmp->next->str = str;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
}

void get_list_array_redir(global_t *global, char *str)
{
    char **array = my_str_to_word_array(str, DELIM);

    global->l_redir = NULL;
    for (int i = 0; array[i]; i++)
        add_back_list_redir(global, array[i]);
    free(array);
}
