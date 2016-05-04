##
## Makefile for Makefile in /home/gassem_a/Minishell/minishell1-2017pso-houtin_r/TEST
##
## Made by aurelien gassemann
## Login   <gassem_a@epitech.net>
##
## Started on  Fri Jan 22 16:14:21 2016 aurelien gassemann
## Last update Sat Apr 16 13:54:13 2016 Aurélien Gassemann
##

NAME	=	mysh

SRC	=	srcs/builtins.c \
		srcs/command_env.c \
		srcs/functions_error.c \
		srcs/functions.c \
		srcs/functions_2.c \
		srcs/get_next_line.c \
		srcs/main.c \
		srcs/minishell.c \
		srcs/command_cd.c \
		srcs/my_exec.c \
		srcs/command_exit.c \
		srcs/command_setenv.c \
		srcs/my_str_to_wordtab.c \
		srcs/command_unsetenv.c \
		srcs/search.c \
		srcs/redirection.c \
		srcs/semicolons.c \

OBJ	=	$(SRC)

RM	=	rm -f

CC	=	gcc -g3


all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ)
		@echo -e -n '\e[1;32m*** Compiled all files ***\e[0m\n'
clean	:
		$(RM) *~
		$(RM) *.o
		$(RM) *#
		@echo -e -n '\e[1;33mDeleted files: \e[0m'
		@echo $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
		@echo -e -n '\e[1;36mDeleted executable file: \e[0m'
		@echo $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
