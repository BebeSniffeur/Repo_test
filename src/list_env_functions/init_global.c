/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** init_global
*/

#include "minishell2.h"

static char *change_str(char **env, char *name_env)
{
    char *string = get_env_var(env, name_env);

    if (string != NULL) {
        string = my_strdup(&string[my_strlen(name_env)]);
        return string;
    }
    return my_strdup("");
}

void init_global(global_t *global, char **env)
{
    global->buffer = NULL;
    global->prompt = NULL;
    global->cmd_return = 0;
    global->env = arraydup(env);
    global->home = change_str(env, "HOME=");
    global->pwd = change_str(env, "PWD=");
    global->oldpwd = change_str(env, "OLDPWD=");
    global->name = change_str(env, "USER=");
    global->path = change_str(env, "PATH=");
    get_list_array(global);
}
