/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** list_cmd_functions
*/

#ifndef LIST_CMD_FUNCTIONS_H
    #define LIST_CMD_FUNCTIONS_H
    #include "all_struct.h"

/*---------------------GET FUNCTIONS----------------------*/
void get_list_array_redir(global_t *global, char *str);
char **get_array_from_list_redir(global_t *global);

/*---------------------CHECK FUNCTIONS----------------------*/
bool check_error_pipe(char *cmd);
int check_command(global_t *global, char *cmd, node_info_t *i_node);
int check_pipe(char *cmd, node_info_t *i_node);
int do_redirection(global_t *global, char *cmd, node_info_t *i_node);
int check_redirection_error(global_t *global, int c_in, int c_out, char *cmd);

/*---------------------MODIFIER LIST----------------------*/
void add_back_list_cmd(global_t *global, node_info_t *i_node);
void remove_node_list_redir(global_t *global, list_str_redir_t *l_redir);

/*--------------------GLOBAL LIST ENV---------------------*/
int init_list_cmd(global_t *global);
void free_list_cmd(list_cmd_t *list);

/*-------------------- REDIRECTION ---------------------*/
void simple_input_redir(global_t *global, node_info_t *i_node);
void double_input_redir(global_t *global, node_info_t *i_node);
void simple_output_redir(global_t *global, node_info_t *i_node);
void double_output_redir(global_t *global, node_info_t *i_node);



int char_in_str(char c, char const *str);
#endif //LIST_CMD_FUNCTIONS_H
