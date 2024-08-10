# Variables

NAME	=	pipex
PROJECT =	Pipex
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

FILES	=	pipex/files pipex/pipex pipex/security pipex/utils pipex/where_doc\
			libft/ft_split libft/libfiles libft/libfiles2 libft/ft_strjoin 

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)pipex/
	@mkdir -p $(OBJ_DIR)libft/

all		:	$(NAME)

$(NAME)	:	$(OBJS) include/pipex.h ./Makefile
	@echo "$(YELLOW)COMPILING $(PROJECT)...$(DEF_COLOR)"
	$(CC) $(FLAG) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(PROJECT) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling:$(DEF_COLOR)"
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJF)
	@echo "$(MAGENTA)$(PROJECT) objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(PROJECT) executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re
