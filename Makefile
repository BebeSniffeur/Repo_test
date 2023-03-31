##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## Makefile
##

SRC = $(shell find ./src -name "*.c")
TESTS = $(shell find ./src ./tests -type f \( -iname "*.c" ! -iname "main.c" \))
OBJET = $(SRC:.c=.o)
NAME = mysh
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
LDFLAGS = -Llib -lmy

$(NAME): $(OBJET)
	@make -C ./lib/my -s
	$(CC) $(OBJET) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "\033[32m==========Compilation done for $(NAME)==========\033[0m"

all: $(NAME)

clean:
	rm -f $(OBJET)
	make fclean -C ./lib/my -s
	@echo "\033[33m======Clean all files *.o of $(NAME) done======\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m=========Clean the binary $(NAME) done=========\033[0m"

g3: fclean
	@make -C lib/my -s
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(NAME) -g3
	@echo "\033[32m==========Compilation done for $(NAME) g3==========\033[0m"

re: fclean all

run: all
	@./$(NAME)

tests_clean:
	@rm -f *.gcda
	@rm -f *.gcno
	@echo "\033[33m========Tests clean========\033[0m"

unit_tests:
	@make -C ./lib/my -s
	$(CC) $(TESTS) -o unit_tests --coverage -lcriterion $(CFLAGS) $(LDFLAGS)
	@echo "\033[32m========Compilation of tests done========\033[0m"

tests_run: unit_tests
	@./unit_tests || make tests_clean -s
	make tests_clean -s
	@rm -f unit_tests
	@echo "\033[32m========Tests done========\033[0m"

.SILENT:$(OBJ)
.PHONY:all g3 clean fclean re run tests_run tests_clean unit_tests
