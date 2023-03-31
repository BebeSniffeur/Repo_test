/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exec_cmd
*/

#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include "minishell2.h"

static void print_error(global_t *global, int status)
{
    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case 11 : my_puterror("Segmentation fault");
                global->cmd_return = 139;
                break;
            case 8 : my_puterror("Floating exception");
                global->cmd_return = 136;
                break;
            default: my_puterror(strerror(errno));
        }
        if (WCOREDUMP(status))
            my_puterror(" (core dumped)");
        my_puterror("\n");
    }
}

static void print_error_execve(char *cmd)
{
    my_puterror(cmd);
    my_puterror(": ");
    if (errno == ENOEXEC) {
        my_puterror(strerror(errno));
        my_puterror(". Wrong Architecture");
    }
    if (errno == EACCES)
        my_puterror(strerror(errno));
    my_puterror(".\n");
}

void exec_cmd(global_t *global, char **cmd, char **env)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == -1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execve(cmd[0], cmd, env) == -1)
            print_error_execve(cmd[0]);
        exit(EXIT_FAILURE);
    }
    print_error(global, status);
    if (WIFEXITED(status))
        global->cmd_return = WEXITSTATUS(status);
}
