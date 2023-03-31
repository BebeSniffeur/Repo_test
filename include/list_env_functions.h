/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_env_functions
*/

#ifndef LIST_ENV_FUNCTIONS_H
    #define LIST_ENV_FUNCTIONS_H
    #include "stdbool.h"
    #include "all_struct.h"

/*---------------------GET FUNCTIONS----------------------*/
void get_list_array(global_t *global);
int len_list_env(list_env_t *list);
char *get_env_var(char **env, char *var);
list_env_t *find_var_list(list_env_t *list, char *env_var);

/*---------------------MODIFIER LIST----------------------*/
void add_back_list_env(global_t *global, char *env);
void add_var_list(global_t *global, char *name_var, char *text_var);
void change_var_list(global_t *global, char *env_var, char *new_var, bool add);
void remove_var_list(list_env_t *list);

/*--------------------GLOBAL LIST ENV---------------------*/
void init_global(global_t *global, char **env);
void free_list(list_env_t *list);

#endif //LIST_ENV_FUNCTIONS_H
