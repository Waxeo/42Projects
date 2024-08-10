# Variables

NAME	=	push_swap
PROJECT =	Push_Swap
CC		=	gcc
FLAG	=	-Wall -Wextra -Werror -MMD -g
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

FILES	=	push_swap utils/push_libft utils/push_utils utils/push_utils2 utils/push_lst_init \
			utils/ft_itoa utils/ft_split instructions/swap_pile instructions/push_pile \
			instructions/rotate_pile instructions/reverse_rotate_pile algo/push_algo \
			algo/push_algo2 utils/algo_utils

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)utils/
	@mkdir -p $(OBJ_DIR)instructions/
	@mkdir -p $(OBJ_DIR)algo/

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@echo "$(YELLOW)COMPILING $(PROJECT)...$(DEF_COLOR)"
	$(CC) $(FLAG) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(PROJECT) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling:$(DEF_COLOR)"
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