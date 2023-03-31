/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** all_struct
*/

#ifndef ALL_STRUCT_H
    #define ALL_STRUCT_H

typedef struct list_env_s {
    char *str;
    struct list_env_s *next;
    struct list_env_s *prev;
} list_env_t;

typedef struct list_tree_cmd_s {
    char *str_cmd;
    char **t_cmd;
    struct list_tree_cmd_s *right;
    struct list_tree_cmd_s *left;
} list_tree_cmd_t;

typedef struct redirection_s {
    bool file_in;
    bool file_out;
    char *name_file_in;
    char *name_file_out;
    int mode;
    mode_t perm;
} redirection_t;

typedef struct node_info {
    bool redirection;
    bool pipe;
    char **t_cmd;
    redirection_t redir;
    list_tree_cmd_t *list_tree;
} node_info_t;

typedef struct list_cmd_s {
    char **t_cmd;
    bool redirection;
    bool pipe;
    redirection_t redir;
    list_tree_cmd_t *tree_cmd;
    struct list_cmd_s *next;
} list_cmd_t;

typedef struct list_str_redir_s {
    char *str;
    struct list_str_redir_s *next;
    struct list_str_redir_s *prev;
} list_str_redir_t;

typedef struct global_s {
    unsigned short cmd_return;
    char *buffer;
    char *path;
    char *name;
    char *home;
    char *pwd;
    char *oldpwd;
    char *prompt;
    char **env;
    list_env_t *l_env;
    list_cmd_t *l_cmd;
    list_str_redir_t *l_redir;
} global_t;

#endif //ALL_STRUCT_H
