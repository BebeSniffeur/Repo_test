/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** unsetenv
*/

#include "minishell2.h"

static void check_remove(list_env_t *tmp, global_t *global)
{
    if (tmp == NULL)
        return;

    if (tmp->next == NULL && tmp->prev == NULL) {
        free(tmp->str);
        free(tmp);
        global->l_env = NULL;
        return;
    }

    if (tmp->prev == NULL) {
        global->l_env = global->l_env->next;
        free(global->l_env->prev->str);
        free(global->l_env->prev);
        global->l_env->prev = NULL;
    } else
        remove_var_list(tmp);
}

void unset_env(global_t *global, list_cmd_t *l_cmd)
{
    char *name_var;
    list_env_t *tmp;

    for (int i = 1; l_cmd->t_cmd[i]; i++) {
        name_var = my_strcat(l_cmd->t_cmd[i], "=");
        if ((tmp = find_var_list(global->l_env, name_var)))
            check_remove(tmp, global);
        free(name_var);
    }
    get_array_from_list(global);
}
