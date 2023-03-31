/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** take_info_test
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (len_of_linked_list, test_function_len_list) {
    global_t global;
    global.l_env = NULL;
    add_back_list_env(&global, "PATH=/usr/local/sbin:/usr/los:/snap/bin");
    add_back_list_env(&global, "PWD=/home/alexis");
    add_back_list_env(&global, "LANG=en_US.UTF-8");
    add_back_list_env(&global, "SHLVL=1");
    add_back_list_env(&global, "_=/usr/bin/env");
    cr_assert_eq(len_list_env(global.l_env), 5);
}

Test (len_of_linked_list, test_function_len_list_env2) {
    global_t global;
    global.l_env = NULL;
    add_back_list_env(&global, "PATH=/usr/leo le rigogole mes:/snap/bin");
    add_back_list_env(&global, "PWD=/home/alexis");
    add_back_list_env(&global, "LANG=en_US.UTF-8");
    add_back_list_env(&global, "SHLVL=1");
    add_back_list_env(&global, "_=/usr/bin/env");
    add_back_list_env(&global, "TEST=TEST");
    cr_assert_eq(len_list_env(global.l_env), 6);
}

Test (len_of_linked_list, test_function_len_list_env3) {
    global_t global;
    global.l_env = NULL;
    add_back_list_env(&global, "PATH=/usr/lo mais non c'est pas vrai");
    add_back_list_env(&global, "PWD=/home/alexis");
    add_back_list_env(&global, "LANG=en_US.UTF-8");
    add_back_list_env(&global, "SHLVL=1");
    add_back_list_env(&global, "_=/usr/bin/env");
    add_back_list_env(&global, "TEST=TEST");
    add_back_list_env(&global, "TEST2=TEST2");
    cr_assert_eq(len_list_env(global.l_env), 7);
}

Test (len_of_linked_list, test_function_len_list_env4) {
    global_t global;
    global.l_env = NULL;
    add_back_list_env(&global, "PATH=/usr/lo mais non c'est pas vrai");
    cr_assert_eq(len_list_env(global.l_env), 1);
}

Test (len_of_linked_list, test_function_len_list_env5) {
    global_t global;
    global.l_env = NULL;
    cr_assert_eq(len_list_env(global.l_env), 0);
}
