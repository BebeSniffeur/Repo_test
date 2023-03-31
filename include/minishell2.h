/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell1
*/

#ifndef MINISHELL2_H
    #define MINISHELL2_H
/*---------------------INCLUDE LIBRAIRIES----------------------*/
    #include <stdlib.h>
    #include <malloc.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

/*-------------------------ALL DEFINE-------------------------*/
    #define ADD 1
    #define IN 1
    #define OUT 0
    #define NO_ADD 0
    #define DELIM " \t\n"
    #define PERM_CREATE_FILE (S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR)
    #define OPEN_MODE (O_RDWR | O_CREAT)

/*-------------------------PROJECT HEADER----------------------*/
    #include "builtins.h"
    #include "get_things.h"
    #include "list_env_functions.h"
    #include "list_cmd_functions.h"
    #include "all_struct.h"
    #include "my.h"


void mysh(global_t *global);
void free_prog(global_t *global);
void exec_cmd(global_t *global, char **cmd, char **env);
void start_minishell(global_t *global);
#endif //MINISHELL2_H
