/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** getstr_prompt
*/

#include "minishell2.h"

void get_str_prompt(global_t *global)
{
    int len_name = my_strlen(global->name);
    size_t size = 0;
    char *PWD = NULL;
    PWD = getcwd(PWD, size);
    char *prompt_pwd = &PWD[6];

    if (global->prompt != NULL && global->prompt[0] != '\0')
        free(global->prompt);
    if (my_strlen(prompt_pwd) == len_name)
        global->prompt = "";
    else
        global->prompt = my_strdup(&prompt_pwd[len_name]);
    free(PWD);
}
