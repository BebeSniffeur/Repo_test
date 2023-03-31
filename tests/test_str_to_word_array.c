/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** test_str_to_word_array
*/

#include "../include/minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (str_to_word_array, test_function_str_to_word_array) {
    char *str = "Hello World";
    char **res = my_str_to_word_array(str, " ");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World");
    cr_assert_null(res[2]);
}

Test (str_to_word_array, test_function_str_to_word_array_with_space) {
    char *str = "Hello World";
    char **res = my_str_to_word_array(str, " ");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World");
    cr_assert_null(res[2]);
}

Test (str_to_word_array, test_function_str_to_word_array_with_space_and_tab) {
    char *str = "Hello\tWorld";
    char **res = my_str_to_word_array(str, " \t");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World");
    cr_assert_null(res[2]);
}

Test (str_to_word_array, test_function_str7) {
    char *str = "Hello\tWorld\\;|;     \n test oui test";
    char **res = my_str_to_word_array(str, " \t\n");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World\\;|;");
    cr_assert_str_eq(res[2], "test");
    cr_assert_str_eq(res[3], "oui");
    cr_assert_str_eq(res[4], "test");
}

Test (str_to_word_array, test_function_str8) {
    char *str = "Hello\tWorld\\;|;     \n test oui test";
    char **res = my_str_to_word_array(str, " \t\n");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World\\;|;");
    cr_assert_str_eq(res[2], "test");
    cr_assert_str_eq(res[3], "oui");
    cr_assert_str_eq(res[4], "test");
}

Test (str_to_word_array, test_function_str9) {
    char *str = "Je sui la pour tester la fonction str_to_wordarray dycg éè è";
    char **res = my_str_to_word_array(str, " \t\n");
    cr_assert_str_eq(res[0], "Je");
    cr_assert_str_eq(res[1], "sui");
    cr_assert_str_eq(res[2], "la");
    cr_assert_str_eq(res[3], "pour");
    cr_assert_str_eq(res[4], "tester");
    cr_assert_str_eq(res[5], "la");
    cr_assert_str_eq(res[6], "fonction");
    cr_assert_str_eq(res[7], "str_to_wordarray");
    cr_assert_str_eq(res[8], "dycg");
    cr_assert_str_eq(res[9], "éè");
    cr_assert_str_eq(res[10], "è");

}

Test (str_to_word_array, test_function_str10) {
    char *str = "Hello\tWorld\\             ;|;     \n test oui test";
    char **res = my_str_to_word_array(str, " \t\n");
    cr_assert_str_eq(res[0], "Hello");
    cr_assert_str_eq(res[1], "World\\");
    cr_assert_str_eq(res[2], ";|;");
    cr_assert_str_eq(res[3], "test");
    cr_assert_str_eq(res[4], "oui");
    cr_assert_str_eq(res[5], "test");
}

Test (str_to_word_array, test_function_str11) {
    char *str = " zld jaeufaoiegf ayg YGSY       UG YGFG AF  YFU             "
                "YG      UEYG UYEFZG      ";
    char **res = my_str_to_word_array(str, " \t\n");
    cr_assert_str_eq(res[0], "zld");
    cr_assert_str_eq(res[1], "jaeufaoiegf");
    cr_assert_str_eq(res[2], "ayg");
    cr_assert_str_eq(res[3], "YGSY");
    cr_assert_str_eq(res[4], "UG");
    cr_assert_str_eq(res[5], "YGFG");
    cr_assert_str_eq(res[6], "AF");
    cr_assert_str_eq(res[7], "YFU");
    cr_assert_str_eq(res[8], "YG");
    cr_assert_str_eq(res[9], "UEYG");
    cr_assert_str_eq(res[10], "UYEFZG");
}
