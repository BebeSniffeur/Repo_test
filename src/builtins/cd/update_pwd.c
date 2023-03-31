/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** update_pwd
*/

#include "minishell2.h"

void update_pwd(global_t *global, char *new_pwd, char *old_pwd)
{
    change_var_list(global, "OLDPWD=", old_pwd, NO_ADD);
    change_var_list(global, "PWD=", new_pwd, NO_ADD);
    free(global->pwd);
    free(global->oldpwd);
    global->pwd = new_pwd;
    global->oldpwd = old_pwd;
}
