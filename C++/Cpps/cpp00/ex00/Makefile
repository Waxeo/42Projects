# Variables

NAME	=	megaphone
PROJECT =	Cpp00 - Ex00
CC		=	c++
FLAG	=	-Wall -Wextra -Werror -std=c++98 -g3

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

FILES	=	megaphone

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

all		:	$(NAME)

$(NAME)	:	$(OBJS) ./Makefile
	@echo "\n"
	$(CC) $(FLAG) megaphone.cpp -o $(NAME)
	@echo "$(YELLOW)$(PROJECT) compiled!$(DEF_COLOR)"

clean	:
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(BLUE)$(PROJECT) objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(BLUE)$(PROJECT) executable cleaned!\n$(DEF_COLOR)"

re		:	fclean all

.PHONY	:	all clean fclean re