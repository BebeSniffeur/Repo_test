/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_redirection_error
*/

#include "minishell2.h"

static void redirect_error(global_t *global, bool sortie)
{
    if (sortie == IN)
        my_puterror("Ambiguous input redirect.\n");
    else
        my_puterror("Ambiguous output redirect.\n");
    global->cmd_return = 1;
}

static bool check_double_redir(global_t *global, char const *cmd, char check)
{
    for (int i = 0; cmd[i] != '\0'; i++)
        if (cmd[i] == check && cmd[i + 1] != check) {
            redirect_error(global, check == '<' ? IN : OUT);
            return true;
        }
    return false;
}

int check_redirection_error(global_t *global, int c_in, int c_out, char *cmd)
{
    if (c_in > 2) {
        redirect_error(global, IN);
        return 84;
    }
    if (c_out > 2) {
        redirect_error(global, OUT);
        return 84;
    }
    if (c_in == 2)
        if (check_double_redir(global, cmd, '<'))
            return 84;
    if (c_out == 2)
        if (check_double_redir(global, cmd, '>'))
            return 84;
    return 0;
}
