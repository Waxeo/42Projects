# Variables

NAME	=	so_long

CC		=	cc
FLAG	=	-Wall -Wextra -Werror -g

DIRLIB	=	./Libft/
FILELIB	=	libft.a
NAMELFT	=	$(addprefix $(DIRLIB), $(FILELIB))

FLAGMLX	=	-L/usr/X11R6/lib -lmlx -lX11 -lXext
DIRMLX	=	./minilibx-linux/
MLXFILE	=	libmlx.a
MLXEXE	= 	$(addprefix $(DIRMLX), $(MLXFILE)) $(FLAGMLX)

SRC_DIR	=	src/
OBJ_DIR =	obj/
INCLUDE	=	-I./include -I./minilibx-linux -I./Libft/include -I/opt/X11/include/X11 


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

FILES	=	main move move2 render parse so_long_parse_utils \
			so_long_parse_utils2 so_long_parse_utils3 so_long_parse_utils4 
			

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

all		:	$(NAME)

lib:
	@echo "$(YELLOW)COMPILING $(DIRLIB)$(DEF_COLOR)"
	@make -C $(DIRLIB)

mlx:
	@echo "$(YELLOW)COMPILING $(DIRMLX)...$(DEF_COLOR)"
	@make -sC $(DIRMLX)
	@echo "$(GREEN)MLX_lib created$(DEF_COLOR)"


$(NAME)	:	lib mlx $(OBJS)
	@echo "$(YELLOW)COMPILING SO_LONG...$(DEF_COLOR)"
	$(CC) $(FLAG) $(OBJS) $(NAMELFT) $(MLXEXE) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)So_long compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@make clean -sC $(DIRMLX)
	@echo "$(MAGENTA)Minilibx objects cleaned!$(DEF_COLOR)"
	@make clean -sC $(DIRLIB)
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(MAGENTA)So_long objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAMELFT)
	@echo "$(YELLOW)Libft cleaned!$(DEF_COLOR)"
	@echo "$(YELLOW)So_long executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re