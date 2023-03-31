/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** getpath
*/

#include "minishell2.h"

char *get_env_var(char **env, char *var)
{
    for (int j = 0; env[j]; j++)
        if (my_strncmp(env[j], var, my_strlen(var)) == 0)
            return env[j];
    return NULL;
}
