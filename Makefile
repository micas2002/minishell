# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 11:39:55 by mibernar          #+#    #+#              #
#    Updated: 2022/12/15 16:12:46 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = minishell.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = main.c input.c lexer.c ft_strcmp.c echo.c pwd.c cd.c signals.c execute_programs.c
SOURCES_DIRECTORY = ./sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft -lreadline
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS)

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "\n$(GREEN)Starting compile$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) 
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)$(RESET)"
	@make -sC $(LIBFT_DIRECTORY)


clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@make -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@make fclean
	@make all

.PHONY	: re fclean clean all