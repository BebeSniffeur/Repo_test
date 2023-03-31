/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** start_minishell
*/

#include <string.h>
#include <errno.h>
#include "minishell2.h"

void free_list_cmd(list_cmd_t *list)
{
    if (list == NULL)
        return;
    if (list->next)
        free_list_cmd(list->next);
    if (list->redirection) {
        if (list->redir.file_in)
            free(list->redir.name_file_in);
        if (list->redir.file_out)
            free(list->redir.name_file_out);
    }
    free(list);
}

static void print_open_error(char *name_file)
{
    my_puterror(name_file);
    my_puterror(": ");
    my_puterror(strerror(errno));
    my_puterror(".\n");
}

static bool change_stdin_stdout(redirection_t redir)
{
    int fd_in;
    int fd_out;

    if (redir.file_in) {
        if ((fd_in = open(redir.name_file_in, O_RDONLY)) == -1) {
            print_open_error(redir.name_file_in);
            return true;
        }
        dup2(fd_in, 0);
        close(fd_in);
    }
    if (redir.file_out) {
        if ((fd_out = open(redir.name_file_out,redir.mode,redir.perm)) == -1) {
            print_open_error(redir.name_file_in);
            return true;
        }
        dup2(fd_out, 1);
        close(fd_out);
    }
    return false;
}

static void start_cmd(global_t *gb, list_cmd_t *l_cmd)
{
    int stdin_dup = dup(0);
    int stdout_dup = dup(1);
    if (l_cmd->redirection)
        if (change_stdin_stdout(l_cmd->redir)) {
            gb->cmd_return = 1;
            return;
        }
    if (!check_builtins(gb, l_cmd)) {
        l_cmd->t_cmd[0] = get_cmd_path(l_cmd->t_cmd[0],my_strdup(gb->path));
        if (l_cmd->t_cmd[0]) {
            exec_cmd(gb, l_cmd->t_cmd, gb->env);
        } else {
            gb->cmd_return = 1;
            l_cmd->t_cmd[0] = my_strdup("");
        }
    }
    if (l_cmd->redirection) {
        dup2(stdin_dup, 0);
        dup2(stdout_dup, 1);
    }
}

void start_minishell(global_t *global)
{
    list_cmd_t *tmp = global->l_cmd;

    while (tmp) {
        start_cmd(global, tmp);
        free_array(tmp->t_cmd);
        tmp = tmp->next;
    }
    free_list_cmd(global->l_cmd);
}
