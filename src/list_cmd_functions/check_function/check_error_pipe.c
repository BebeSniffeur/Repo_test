/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_redirection_with_pipe
*/

#include "minishell2.h"

bool check_error_pipe(char *cmd)
{
    if (my_str_have_only_that(cmd, DELIM)) {
        my_puterror("Invalid null command.\n");
        return false;
    }
    if (char_in_str('>', cmd)) {
        my_puterror("Ambiguous output redirect.\n");
        return false;
    }
    return true;
}
