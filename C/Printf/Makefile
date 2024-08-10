# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 13:47:38 by mgauvrit          #+#    #+#              #
#    Updated: 2022/12/08 14:42:42 by mgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = include
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
COMP = gcc
FLAGS = -Wall -Werror -Wextra -I
RM = rm -f
AR = ar rcs

FILES = ft_printf ft_printcs ft_printid ft_printx ft_print_ptr

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		$(AR) $(NAME) $(OBJ) 
$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
		@$(COMP) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: 	clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(LIBFT)/libft.a

re: fclean all

.PHONY : all clean fclean re
