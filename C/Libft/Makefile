# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 13:47:38 by mgauvrit          #+#    #+#              #
#    Updated: 2022/12/13 15:16:47 by mgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

SRC_DIR		=    src/
OBJ_DIR		=    obj/
NAME		=    libft.a
INCLUDE		=    ./include
CC			=    gcc
CFLAGS		=    -Wall -Wextra -Werror -I


# Colors

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# Sources

FILES    =    ft_is/ft_isalpha ft_is/ft_isdigit ft_is/ft_isalnum \
            ft_is/ft_isascii ft_is/ft_isprint \
            ft_mem/ft_memset ft_mem/ft_memcpy ft_mem/ft_memmove ft_mem/ft_memchr \
            ft_mem/ft_memcmp ft_mem/ft_calloc ft_mem/ft_bzero \
            ft_put/ft_putchar_fd ft_put/ft_putstr_fd \
            ft_put/ft_putendl_fd ft_put/ft_putnbr_fd \
            ft_str/ft_strlcpy ft_str/ft_strlcat ft_str/ft_strdup \
            ft_str/ft_strncmp ft_str/ft_strlen ft_str/ft_strnstr \
            ft_str/ft_strtrim ft_str/ft_strchr ft_str/ft_strrchr \
            ft_str/ft_strjoin ft_str/ft_striteri ft_str/ft_strmapi \
            ft_str/ft_substr ft_str/ft_split \
            ft_to/ft_atoi ft_to/ft_itoa ft_to/ft_toupper ft_to/ft_tolower \
            ft_lst/ft_lstnew ft_lst/ft_lstsize ft_lst/ft_lstlast \
            ft_lst/ft_lstadd_back ft_lst/ft_lstadd_front ft_lst/ft_lstdelone \
            ft_lst/ft_lstclear ft_lst/ft_lstiter ft_lst/ft_lstmap \
            ft_print/ft_printcs ft_print/ft_printf ft_print/ft_print_ptr \
            ft_print/ft_printid ft_print/ft_printx \
			get_next_line 

SRCS    =    $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS    =    $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF    =    .cache_exists

all        :    $(NAME)

$(OBJF)    :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)ft_is/
	@mkdir -p $(OBJ_DIR)ft_lst/
	@mkdir -p $(OBJ_DIR)ft_mem/
	@mkdir -p $(OBJ_DIR)ft_print/
	@mkdir -p $(OBJ_DIR)ft_put/
	@mkdir -p $(OBJ_DIR)ft_str/
	@mkdir -p $(OBJ_DIR)ft_to/

$(NAME)    :    $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o    : $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling:$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean    :
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(BLUE)Objects cleaned!$(DEF_COLOR)"

fclean    :    clean
	@rm -f $(NAME)
	@echo "$(CYAN)Libft executable cleaned!$(DEF_COLOR)"

re        :    fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY    :    all clean fclean re
