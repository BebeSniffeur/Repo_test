/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** change_dir
*/

#include <string.h>
#include <errno.h>
#include "minishell2.h"

static int do_chdir(char *path)
{
    if (chdir(path)) {
        my_puterror(path);
        my_puterror(": ");
        my_puterror(strerror(errno));
        my_puterror(".\n");
        return 1;
    }
    return 0;
}

void change_dir(global_t *global, list_cmd_t *l_cmd)
{
    char *cd_path = NULL, *new_pwd = NULL, *old_pwd = NULL;
    size_t size = 0;

    if (check_error_cd(global, l_cmd))
        return;

    old_pwd = getcwd(old_pwd, size);
    cd_path = change_cd_path(global, l_cmd, l_cmd->t_cmd[1]);

    if (do_chdir(cd_path)) {
        global->cmd_return = 1;
        free(cd_path);
        free(old_pwd);
        return;
    }
    global->cmd_return = 0;
    free(cd_path);
    update_pwd(global, getcwd(new_pwd, size), old_pwd);
    get_array_from_list(global);
}
