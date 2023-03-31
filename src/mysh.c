/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** mysh
*/

#include <string.h>
#include "minishell2.h"

static void print_prompt(global_t *global)
{
    if (isatty(STDIN_FILENO))
        my_printf("~%s %d> ", global->prompt, global->cmd_return);
}

void free_prog(global_t *global)
{
    free_list(global->l_env);
    free_array(global->env);
    free(global->buffer);
    free(global->name);
    free(global->home);
    free(global->pwd);
    free(global->oldpwd);
    free(global->path);
    if (global->prompt != NULL && global->prompt[0] != '\0')
        free(global->prompt);
}

void mysh(global_t *global)
{
    size_t buf_size = 0;

    while (getline(&global->buffer, &buf_size, stdin) > 0) {
        if (my_str_have_only_that(global->buffer, DELIM)) {
            print_prompt(global);
            continue;
        }
        if (init_list_cmd(global)) {
            print_prompt(global);
            continue;
        }
        start_minishell(global);

        print_prompt(global);
    }
}
