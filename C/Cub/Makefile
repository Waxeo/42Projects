# Variables

NAME	=	cub3D

CC		=	cc
FLAG	=	-Wall -Wextra -Werror -g

DIRLIB	=	./Libft/
FILELIB	=	libft.a
NAMELFT	=	$(addprefix $(DIRLIB), $(FILELIB))

FLAGMLX	=	-L minilibx-linux/ -lmlx -lX11 -lXext -g3 -lm
DIRMLX	=	./minilibx-linux/
MLXFILE	=	libmlx.a
MLXEXE	= 	$(addprefix $(DIRMLX), $(MLXFILE)) $(FLAGMLX)

SRC_DIR	=	src/
OBJ_DIR =	obj/
INCLUDE	=	-I./include -I./minilibx-linux -I./Libft/include 


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

FILES	=	main  \
			parsing/parsing parsing/parse_utils parsing/parse_utils2 \
			parsing/parse_utils3 \
			raycasting/ray_init raycasting/event raycasting/raycasting \
			raycasting/pixel raycasting/mouse \
			utils/utils utils/event_utils
			

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/raycasting
	@mkdir -p $(OBJ_DIR)/utils


all		:	lib mlx $(NAME)

lib:
	@echo "$(YELLOW)COMPILING $(DIRLIB)$(DEF_COLOR)"
	@make -C $(DIRLIB)

mlx:
	@echo "$(YELLOW)COMPILING $(DIRMLX)...$(DEF_COLOR)"
	@make -sC $(DIRMLX)
	@echo "$(GREEN)MLX_lib created$(DEF_COLOR)"

$(NAME)	:  $(OBJS) Makefile include/mlx.h include/libft.h
	@echo "$(YELLOW)COMPILING Cub3D...$(DEF_COLOR)"
	@$(CC) $(FLAG) $(OBJS) $(NAMELFT) $(MLXEXE) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)Cub3D compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c  include/cub.h | $(OBJF) 
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

clean	:
	@make clean -sC $(DIRMLX)
	@echo "$(MAGENTA)Minilibx objects cleaned!$(DEF_COLOR)"
	@make clean -sC $(DIRLIB)
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(MAGENTA)Cub3D objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f $(NAME)
	@rm -f $(NAMELFT)
	@echo "$(YELLOW)Libft cleaned!$(DEF_COLOR)"
	@echo "$(YELLOW)Cub3D executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re