/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** get_cmd_path
*/

#include <string.h>
#include <errno.h>
#include "minishell2.h"

static void free_get_cmd(char *cmd, char *new_cmd, char *env_path)
{
    free(cmd);
    free(new_cmd);
    free(env_path);
}

char *get_cmd_path(char *cmd, char *env_path)
{
    char *path = NULL, *check_path = NULL, *new_cmd;

    if (char_in_str('/', cmd) && access(cmd, X_OK) == 0) {
        free(env_path);
        return cmd;
    }
    new_cmd = my_strcat("/", cmd);
    path = strtok(env_path, ":");
    while (path) {
        check_path = my_strcat(path, new_cmd);
        if (access(check_path, X_OK) == 0) {
            free_get_cmd(cmd, new_cmd, env_path);
            return check_path;
        }
        free(check_path);
        path = strtok(NULL, ":");
    }
    my_printf("%s: Command not found.\n", cmd);
    free_get_cmd(cmd, new_cmd, env_path);
    return NULL;
}
