/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_str_have_that
*/

#include "stdbool.h"
int char_in_str(char c, char const *str);

bool my_str_have_only_that(char const *str, char const *check_char)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!char_in_str(str[i], check_char))
            return false;
    return true;
}
