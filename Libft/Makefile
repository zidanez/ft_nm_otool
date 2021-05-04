# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:07:00 by fnancy            #+#    #+#              #
#    Updated: 2021/05/04 14:20:50 by fnancy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
WORK_SPACE = $(shell pwd)
CC = gcc
CCFLAGS = -Wall -Werror -Wextra -g
EMPTY =
TMP =

H_DIR = $(WORK_SPACE)/include
O_DIR = $(WORK_SPACE)/objs
A_DIR = $(WORK_SPACE)/alibs
C_DIR = $(WORK_SPACE)/src

STD_LIB =		source
STD_LIBS =		$(patsubst %, libft%.a, $(STD_LIB))
LIBS =			$(patsubst %, $(A_DIR)/%, $(STD_LIBS))
ALL_O =			$(foreach lib, $(shell echo $(STD_LIB) | tr a-z A-Z), $(patsubst %, $(O_DIR)/%.o, $($(lib))))

SOURCEO =		$(patsubst %, $(O_DIR)/%.o, $(SOURCE))
SOURCES =		$(patsubst %, $(C_DIR)/%.c, $(SOURCE))
SOURCE  =		ft_atoi ft_bzero ft_ilen ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_memalloc ft_memccpy ft_memchr ft_memcmp \
ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd \
ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter \
ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ \
ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_tolower ft_toupper 

all: $(NAME)

$(NAME): $(ALL_O)
	@ar rc $(NAME) $(ALL_O);
	@ranlib $(NAME);

o_dir:
	@if ! [ -d $(O_DIR) ]; then mkdir $(O_DIR); fi;

a_dir: o_dir
	@if ! [ -d $(A_DIR) ]; then mkdir $(A_DIR); fi;


$(O_DIR)/%.o: $(C_DIR)/%.c
	@make o_dir
	@echo "\033[1m\033[38;2;0;60;255mCompiling : \033[7m$<\033[0m\033[1m\033[38;2;0;60;255m <<\033[0m";
	@$(CC) $(CCFLAGS) -c $< -o $@ -I$(H_DIR);

libft%.a: a_dir
	$(eval EMPTY = $(shell echo $(patsubst libft%.a, %O, $@) | tr a-z A-Z))
	@echo "$@ :\n";
	@make $($(EMPTY));
	@ar rc $(A_DIR)/$@ $($(EMPTY));
	@ranlib $(A_DIR)/$@;
	@echo "\n\033[1m\033[38;2;0;255;0m$@ is compiled\033[0m\n";

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm -rf $(A_DIR)
	@rm -f $(NAME)

re_libft%.a:
	$(eval EMPTY = $(shell echo $(patsubst re_libft%.a, %O, $@) | tr a-z A-Z))
	$(eval TMP = $(patsubst re_%, %, $@))
	@rm -f $(A_DIR)/$(TMP);
	@rm -f $($(EMPTY));
	@make $(TMP);

re: fclean all
