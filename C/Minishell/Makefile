# Variables

NAME	=	minishell
PROJECT =	Minishell
CC		=	cc
FLAG	=	-Wall -Wextra -Werror -g3

SRC_DIR	=	src/
OBJ_DIR =	obj/
INCLUDE	=	-I./include


# Colors

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# Sources

FILES	=	main \
			env/init env/shlvl env/env_utils \
			builtin/cd builtin/echo builtin/env builtin/exit builtin/error \
			builtin/export builtin/pwd builtin/unset builtin/builtins_utils \
			parsing/quote parsing/command parsing/expand parsing/space_line \
			parsing/expand_utils parsing/command_utils \
			pipex/files pipex/pipex_utils pipex/pipex_utils2 pipex/where_doc_utils \
			pipex/pipex pipex/security pipex/where_doc pipex/exec pipex/free \
			utils/lst_utils utils/ft_strjoin utils/ft_split \
			utils/utils utils/utils2 utils/utils3 utils/itoa \
			utils/get_next_line \
			signal/signal

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/env
	@mkdir -p $(OBJ_DIR)/builtin
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/signal
	@mkdir -p $(OBJ_DIR)/pipex

all		:	$(NAME)

$(NAME)	:	$(OBJS) Makefile include/minishell.h
	@echo "$(YELLOW)COMPILING $(PROJECT)...$(DEF_COLOR)"
	$(CC) $(OBJS) $(FLAG) $(INCLUDE) -lreadline -o $(NAME)
	@echo "$(GREEN)$(PROJECT) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(MAGENTA)$(PROJECT) objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(PROJECT) executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re
