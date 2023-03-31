/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** get_things
*/

#ifndef GET_THINGS_H
    #define GET_THINGS_H
    #include "all_struct.h"

void get_array_from_list(global_t *global);
void get_str_prompt(global_t *global);
char *get_cmd_path(char *cmd, char *path);
#endif //GET_THINGS_H
