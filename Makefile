NAME = minishell

LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = minishell.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = main.c input.c lexer.c lexer_utils.c echo.c pwd.c cd.c signals.c env.c unset.c export.c \
		 execute_programs.c free.c execute_programs_utils.c error_handler.c

SOURCES_DIRECTORY = ./sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft -lreadline
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS)

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
YELLOW = \033[0;93m
RESET = \033[0m

all: ## Compiles the whole project
	@make -s $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "\n\nStarting compile, now have some $(BLUE)colorful $(RED)text $(YELLOW)slayyyy$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)object files$(RESET) were created and have come to free us, $(YELLOW)monkeys$(RESET) united."
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME)$(RESET) was created, like $(BLUE)god$(RESET) intended"

$(OBJECTS_DIRECTORY): ## Creates the objects directory
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME): $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created $(YELLOW)WOW $(BLUE)OMG$(RESET) i'm so $(GREEN)talented$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) ## Compiles each '*.c'
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT): ## Compiles the libft
	@echo "$(CYAN)$(NAME): $(RESET)Creating $(GREEN)$(LIBFT)$(RESET)"
	@make -sC $(LIBFT_DIRECTORY) --no-print-directory


clean: ## Cleans all the '*.o' files and deletes the objects directory
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME): $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted, *insert sadge emote*"
	@echo "$(CYAN)$(NAME): $(RED)object files$(RESET) deleted, it was like Voldemort said *FETUS DELETUS*"
	@make -sC $(LIBFT_DIRECTORY) clean --no-print-directory

fclean: clean ## Calls clean and deletes all executables and compiled libs
	@echo "$(CYAN)$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@make -sC $(LIBFT_DIRECTORY) fclean --no-print-directory

re: ## Deep cleans the project and recompiles it
	@make -s fclean
	@make -s all
	
help: ## Shows all the options and it's uses
	@echo "usage: make [target]"
	@echo ""
	@egrep "^(.+)\:\ .*##\ (.+)" ${MAKEFILE_LIST} | sed 's/:.*##/#/' | column -t -c 2 -s '#'

.PHONY	: re fclean clean all