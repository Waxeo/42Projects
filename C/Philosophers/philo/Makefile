# Variables

NAME	=	philo
PROJECT =	Philosophers
CC		=	cc 
FLAG	=	-pthread -Wall -Wextra -Werror -g

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

FILES	= init libft_utils philo_utils philo_utils2 philo

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

all		:	$(NAME)

$(NAME)	:	$(OBJS) include/philo.h ./Makefile
	@echo "\n"
	@$(CC) $(FLAG) $(OBJS) $(NAMELFT) $(INCLUDE) -o $(NAME)
	@echo "$(YELLOW)$(PROJECT) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@printf "$(CYAN)Generating $(PROJECT) objects... %-33.33s\r" $@
	@$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(BLUE)$(PROJECT) objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(BLUE)$(PROJECT) executable cleaned!\n$(DEF_COLOR)"

re		:	fclean all

.PHONY	:	all clean fclean re
