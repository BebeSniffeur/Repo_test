/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main du minishell
*/

#include "minishell2.h"

static int check_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("USAGE : ./mysh\n");
        return 0;
    }
    if (ac > 1) {
        my_puterror("Error: Too many arguments.\n");
        return 84;
    }
    return 0;
}

int main(int ac, char *av[], char *env[])
{
    global_t global;

    if (check_error(ac, av))
        return 84;
    init_global(&global, env);

    if (isatty(STDIN_FILENO)) {
        get_str_prompt(&global);
        my_printf("~%s lea leoa cczb $> ", global.prompt);
    }
    mysh(&global);
    if (isatty(STDIN_FILENO))
        my_printf("Good Bye %s !\n", global.name);
    free_prog(&global);
    return global.cmd_return;
}
