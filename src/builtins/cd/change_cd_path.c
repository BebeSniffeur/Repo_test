/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** change_cd_path
*/

#include "minishell2.h"

char *change_cd_path(global_t *global, list_cmd_t *l_cmd, char *path)
{
    if (len_array(l_cmd->t_cmd) == 1)
        return my_strdup(global->home);

    if (!my_strncmp(path, "-", 1))
        return my_strdup(global->oldpwd);

    if (!my_strcmp(path, "~"))
        return my_strdup(global->home);

    if (my_strlen(path) > 1 && !my_strncmp(path, "~", 1)) {
        char *home = global->home;
        char *new_path = my_strcat(home, &path[1]);
        return new_path;
    }
    return my_strdup(l_cmd->t_cmd[1]);
}
