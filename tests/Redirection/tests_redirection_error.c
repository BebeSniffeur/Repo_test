/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** tests_redirection_error
*/

#include "../../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test (test_error_redirection, test_function_error_redirection) {
    char *cmd = "ls > test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_eq(result, 0);
}

Test (test_error_redirection, test_function_error_redirection2,
.init = redirect_all_stdout) {
    char *cmd = "ls > test > test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
    cr_assert_eq(result, 84);
}

Test (test_error_redirection, test_function_error_redirection3,
.init = redirect_all_stdout) {
    char *cmd = "ls < test < test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    cr_assert_eq(result, 84);
}

Test (test_error_redirection, test_function_error_redirection4,
.init = redirect_all_stdout) {
    char *cmd = "ls <> > test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
    cr_assert_eq(result, 84);
}

Test (test_error_redirection, test_function_error_redirection5,
.init = redirect_all_stdout) {
    char *cmd = "ls <                          < test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    cr_assert_eq(result, 84);
}

Test (test_error_redirection, test_function_error_redirection6,
.init = redirect_all_stdout) {
    char *cmd = "ls te<st < test";
    global_t global;
    int c_in = count_char_in_str(cmd, '<');
    int c_out = count_char_in_str(cmd, '>');
    int result = check_redirection_error(&global, c_in, c_out, cmd);

    cr_assert_stderr_eq_str("Ambiguous input redirect.\n");
    cr_assert_eq(result, 84);
}
