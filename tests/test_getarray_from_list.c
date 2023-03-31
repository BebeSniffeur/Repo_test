/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_getarray_from_list
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>

Test (getarray_from_list, test_function_get_array) {
    global_t global;

    global.l_env = NULL;
    global.env = malloc(sizeof(char *) * (1));
    add_var_list(&global, "PATH=", "/bin");
    add_var_list(&global, "PWD=", "/home");
    get_array_from_list(&global);
    cr_assert_str_eq(global.env[0], "PATH=/bin");
    cr_assert_str_eq(global.env[1], "PWD=/home");
    free_array(global.env);
}

Test (getarray_from_list, test_function_get_array2) {
    global_t global;

    global.l_env = NULL;
    global.env = malloc(sizeof(char *) * (1));
    add_var_list(&global, "PATH=", "/bin");
    add_var_list(&global, "PWD=", "/home");
    add_var_list(&global, "LANG=", "en_US.UTF-8");
    add_var_list(&global, "SHLVL=", "1");
    add_var_list(&global, "_=", "/usr/bin/env");
    get_array_from_list(&global);
    cr_assert_str_eq(global.env[0], "PATH=/bin");
    cr_assert_str_eq(global.env[1], "PWD=/home");
    cr_assert_str_eq(global.env[2], "LANG=en_US.UTF-8");
    cr_assert_str_eq(global.env[3], "SHLVL=1");
    cr_assert_str_eq(global.env[4], "_=/usr/bin/env");
    free_array(global.env);
}
