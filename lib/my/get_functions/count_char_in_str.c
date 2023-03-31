/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** count_char_in_str
*/

int count_char_in_str(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count ++;
    return count;
}
