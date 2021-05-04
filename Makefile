# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 12:54:32 by fnancy            #+#    #+#              #
#    Updated: 2021/05/04 14:19:52 by fnancy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(OTOOL), $(NM), clean, fclean, re, make_lft

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
NM = ft_nm
OTOOL = ft_otool
FLAGS = -Wall -Wextra

WS_PATH = $(shell pwd)

SRC_PATH_NM = $(WS_PATH)/src/nm/
SRC_PATH_OTOOL = $(WS_PATH)/src/otool/

OBJ_PATH_NM = $(WS_PATH)/objs/nm/
OBJ_PATH_OTOOL = $(WS_PATH)/objs/otool/

INC_PATH_NM = $(WS_PATH)/include/nm
INC_PATH_OTOOL = $(WS_PATH)/include/otool

LIB_PATH = $(WS_PATH)/Libft/
LIB_INC_PATH = $(LIB_PATH)include/

SRC_OTOOL = $(addprefix $(SRC_PATH_OTOOL), $(SRC_FILES_OTOOL))
SRC_NM = $(addprefix $(SRC_PATH_NM), $(SRC_FILES_NM))



INC_NM = $(addprefix -I, $(INC_PATH_NM))
INC_OTOOL = $(addprefix -I, $(INC_PATH_OTOOL))
INC_LIB = $(addprefix -I, $(LIB_INC_PATH))

SRC_FILES_NM = types/macho64/macho64.c types/macho32/macho32.c types/arch/arch.c types/fat32/fat32.c \
types/fat64/fat64.c section.c ppc.c printer.c printer_helper.c main.c utils.c 
SRC_FILES_OTOOL =  types/macho64/macho64.c types/macho32/macho32.c types/arch/arch.c types/fat32/fat32.c \
types/fat64/fat64.c section.c ppc.c printer.c main.c utils.c

ADD_OBJ_NM = $(addprefix $(OBJ_PATH_NM), types/macho64 types/macho32 types/arch types/fat32 types/fat64)
ADD_OBJ_OTOOL = $(addprefix $(OBJ_PATH_OTOOL), types/macho64 types/macho32 types/arch types/fat32 types/fat64)


OBJ_NM = $(addprefix $(OBJ_PATH_NM), $(SRC_FILES_NM:.c=.o))
OBJ_OTOOL = $(addprefix $(OBJ_PATH_OTOOL), $(SRC_FILES_OTOOL:.c=.o))


# ************************************************************************** #
#                                   Rules                                    #
# ************************************************************************** #

all: make_lft $(NM) $(OTOOL)

$(NM): $(OBJ_NM)
	@gcc $(FLAGS) -o $(NM) $(INC_NM) $(INC_LIB) $(OBJ_NM) -L $(LIB_PATH) -lft -lncurses -g

$(OTOOL): $(OBJ_OTOOL)
	@gcc $(FLAGS) -o $(OTOOL) $(INC_OTOOL) $(INC_LIB) $(OBJ_OTOOL) -L $(LIB_PATH) -lft -lncurses -g

$(OBJ_PATH_NM)%.o: $(SRC_PATH_NM)%.c $(INC_PATH_NM)
	@echo "$(GREY)$(UNDERLINE)CREATING >> $@$(ESCN)"
	@mkdir -p $(OBJ_PATH_NM)
	@mkdir -p $(ADD_OBJ_NM)
	@gcc $(INC_NM) $(INC_LIB) -o $@ -c $<

$(OBJ_PATH_OTOOL)%.o: $(SRC_PATH_OTOOL)%.c $(INC_PATH_OTOOL)
	@echo "$(AQUA)$(UNDERLINE)CREATING >> $@$(ESCN)"
	@mkdir -p $(OBJ_PATH_OTOOL)
	@mkdir -p $(ADD_OBJ_OTOOL)
	@gcc $(INC_OTOOL) $(INC_LIB) -o $@ -c $<

make_lft:
	@echo "$(GREEN)$(UNDERLINE)COMPILING LIBFT$(ESCN)"
	@make -C $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH_NM)
	@rm -rf $(OBJ_PATH_OTOOL)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NM)
	@rm -f $(OTOOL)
	@make fclean -C $(LIB_PATH)

re: fclean all

