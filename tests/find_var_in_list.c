/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** find_var_in_list
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (find_var_in_linked_list, test_function_find_var) {
    global_t global;
    list_env_t *list = malloc(sizeof(list_env_t));
    list->str = "PATH=/usr/lococo lico tu es moche bin";
    list->next = NULL;
    list->prev = NULL;
    global.l_env = list;
    cr_assert_eq(find_var_list(global.l_env, "PATH="), list);
    cr_assert_eq(find_var_list(global.l_env, "PWD="), NULL);
}

Test (find_var_in_linked_list, test_function_find_var2) {
    global_t global;
    list_env_t *list = malloc(sizeof(list_env_t));
    list->str = "PATH=/usrmais oui c'est moi jammybin";
    list->next = NULL;
    list->prev = NULL;
    global.l_env = list;
    list->next = malloc(sizeof(list_env_t));
    list->next->str = "PWD=/home/alexis";
    list->next->next = NULL;
    list->next->prev = list;
    cr_assert_eq(find_var_list(global.l_env, "PATH="), list);
    cr_assert_eq(find_var_list(global.l_env, "PWD="), list->next);
    cr_assert_eq(find_var_list(global.l_env, "LANG="), NULL);
}

Test (find_var_in_linked_list, test_function_find_var3) {
    global_t global;
    list_env_t *list = malloc(sizeof(list_env_t));
    list->str = "PATH=/usr/ coucou les musulmans moi je mange la glace:/";
    list->next = NULL;
    list->prev = NULL;
    global.l_env = list;
    list->next = malloc(sizeof(list_env_t));
    list->next->str = "PWD=/home/alexis";
    list->next->next = NULL;
    list->next->prev = list;
    list->next->next = malloc(sizeof(list_env_t));
    list->next->next->str = "LANG=en_US.UTF-8";
    list->next->next->next = NULL;
    list->next->next->prev = list->next;
    cr_assert_eq(find_var_list(global.l_env, "PATH="), list);
    cr_assert_eq(find_var_list(global.l_env, "PWD="), list->next);
    cr_assert_eq(find_var_list(global.l_env, "LANG="), list->next->next);
    cr_assert_eq(find_var_list(global.l_env, "SHLVL="), NULL);
}
