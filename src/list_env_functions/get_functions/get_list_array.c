/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** getlist_array
*/

#include "minishell2.h"

void get_list_array(global_t *global)
{
    global->l_env = NULL;
    for (int i = 0; global->env[i]; i++)
        add_back_list_env(global, global->env[i]);
}
