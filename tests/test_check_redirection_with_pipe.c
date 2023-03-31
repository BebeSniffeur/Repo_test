/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_check_redirection_with_pipe
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test (test_check_pipe_command, test_function_check_pipe_command1,
.init = redirect_all_stdout) {
    char *cmd = "ls > test";
    bool result = check_error_pipe(cmd);

    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
    cr_assert_eq(result, false);
}

Test (test_check_pipe_command, test_function_check_pipe_command2) {
    char *cmd = "ls test";
    bool result = check_error_pipe(cmd);

    cr_assert_eq(result, true);
}

Test (test_check_pipe_command, test_function_check_pipe_command3) {
    char *cmd = "ls < test";
    bool result = check_error_pipe(cmd);

    cr_assert_eq(result, true);
}

Test (test_check_pipe_command, test_function_check_pipe_command4,
.init = redirect_all_stdout) {
    char *cmd = "  \t \t\n \n\t   ";
    bool result = check_error_pipe(cmd);

    cr_assert_stderr_eq_str("Invalid null command.\n");
    cr_assert_eq(result, false);
}
