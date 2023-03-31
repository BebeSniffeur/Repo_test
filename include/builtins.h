/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** builtins
*/

#ifndef BUILTINS_H
    #define BUILTINS_H
    #include "all_struct.h"

/*---------------------CD BUILTINS----------------------*/
void change_dir(global_t *global, list_cmd_t *l_cmd);
char *change_cd_path(global_t *global, list_cmd_t *l_cmd, char *path);
void update_pwd(global_t *global, char *new_pwd, char *old_pwd);
int check_error_cd(global_t *global, list_cmd_t *l_cmd);

/*---------------------SETENV BUILTINS----------------------*/
void set_env(global_t *global, list_cmd_t *l_cmd);

/*---------------------UNSETENV BUILTINS----------------------*/
void unset_env(global_t *global, list_cmd_t *l_cmd);

int check_builtins(global_t *global, list_cmd_t *l_cmd);

#endif //BUILTINS_H
