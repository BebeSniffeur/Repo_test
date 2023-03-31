/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_printf(const char *format, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, test_pourcentage_string, .init = redirect_all_stdout) {
    my_printf("%%s");
    cr_assert_stdout_eq_str("%s");
}

Test (my_printf, test_pourcentage_string_width, .init = redirect_all_stdout) {
    my_printf("%10s", "test");
    cr_assert_stdout_eq_str("      test");
}

Test (my_printf, test_string_width_zero, .init = redirect_all_stdout) {
    my_printf("%010s", "test");
    cr_assert_stdout_eq_str("000000test");
}

Test (my_printf, test_string_width_minus, .init = redirect_all_stdout) {
    my_printf("%-10s", "test");
    cr_assert_stdout_eq_str("test      ");
}

Test (my_printf, test_string_width_zero_minus, .init = redirect_all_stdout) {
    my_printf("%-010s", "test");
    cr_assert_stdout_eq_str("test000000");
}

Test (my_printf, test_string_width_minus_zero, .init = redirect_all_stdout) {
    my_printf("%-0s", "test");
    cr_assert_stdout_eq_str("test");
}

Test (my_printf, test_string_width_min_zero, .init = redirect_all_stdout) {
    my_printf("%-0s", "test");
    cr_assert_stdout_eq_str("test");
}
