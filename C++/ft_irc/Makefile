# Variables

NAME	=	ircserv
PROJECT =	Irc
CC		=	c++
FLAG	=	-Wall -Wextra -Werror -g3 -std=c++98

SRC_DIR	=	srcs/
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
			Server Client utils Channel \
			Commands/nick Commands/pass Commands/user Commands/pong \
			Commands/mode Commands/privmsg Commands/quit Commands/join \
			Commands/topic Commands/kick Commands/invite 

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

DEP		=	Server Client utils	Channel
DEPS	=	$(addprefix include/, $(addsuffix .hpp, $(DEP)))
DEPEN	=	$(DEPS) Makefile

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/Commands

OBJF_EXISTS := $($(OBJ_DIR)/.cache_exists)

ifeq ($(OBJF_EXISTS),)
	MAKE_DIR = @mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/Commands
else
	MAKE_DIR = @echo
endif

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@echo "$(YELLOW)COMPILING $(PROJECT)...$(DEF_COLOR)"
	$(CC) $(FLAG) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)$(PROJECT) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp $(DEPEN)
	$(MAKE_DIR)
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)$(PROJECT) objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(PROJECT) executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re