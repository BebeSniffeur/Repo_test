/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** segfault
*/

void main(void)
{
    char *test = "leo";

    for (int i = 0; i < 5; i++)
        test[i] = 'a';
}
