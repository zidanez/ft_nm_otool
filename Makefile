# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 12:54:32 by fnancy            #+#    #+#              #
#    Updated: 2021/05/03 15:23:48 by fnancy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re, make_lft

# ************************************************************************** #
#                           colors                                           #
# ************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
ESCN = \033[0m

# ************************************************************************** #
#                           Configuration                                    #
# ************************************************************************** #
NAME = ft_nm
FLAGS = -Wall -Wextra

WS_PATH = $(shell pwd)
SRC_PATH = $(WS_PATH)/src/
OBJ_PATH = $(WS_PATH)/objs/
INC_PATH = $(WS_PATH)/include/
LIB_PATH = $(WS_PATH)/Libft/
LIB_INC_PATH = $(LIB_PATH)include/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(LIB_INC_PATH))

SRC_FILES = nm/main.c nm/utils.c nm/types/macho64/macho64.c nm/types/macho32/macho32.c nm/types/arch/arch.c nm/types/fat32/fat32.c \
nm/types/fat64/fat64.c nm/section.c nm/ppc.c nm/printer.c nm/printer_helper.c

ADD_OBJ = $(addprefix $(OBJ_PATH), nm otool nm/types/macho64 nm/types/macho32 nm/types/arch nm/types/fat32 nm/types/fat64)


OBJ_FILES = $(SRC_FILES:.c=.o)

# ************************************************************************** #
#                                   Rules                                    #
# ************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@make make_lft
	@gcc $(FLAGS) -o $(NAME) $(INC) $(INC_LIB) $(OBJ) -L $(LIB_PATH) -lft -lncurses -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(GREY)$(UNDERLINE)CREATING >> $@$(ESCN)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(ADD_OBJ)
	@gcc $(INC) $(INC_LIB) -o $@ -c $<

make_lft:
	@echo "$(GREEN)$(UNDERLINE)COMPILING LIBFT$(ESCN)"
	@make -C $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all

