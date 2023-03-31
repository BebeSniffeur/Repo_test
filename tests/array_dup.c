/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** array_dup
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (array_dup, test_function_array_dup) {
    char *array[] = {"PATH=/Je m'en fiche", NULL};
    char **new_array = arraydup(array);
    cr_assert_str_eq(new_array[0], array[0]);
    cr_assert_eq(new_array[1], NULL);
}

Test (array_dup, test_function_array_dup2) {
    char *array[] = {"PATH=coucou c'est moi","PWD=/home/alexis", NULL};
    char **new_array = arraydup(array);
    cr_assert_str_eq(new_array[0], array[0]);
    cr_assert_str_eq(new_array[1], array[1]);
    cr_assert_eq(new_array[2], NULL);
}
