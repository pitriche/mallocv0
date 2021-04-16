# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:21:44 by pitriche          #+#    #+#              #
#    Updated: 2020/07/09 18:41:17 by pierre42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[032m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# **************************************************************************** #

CC = cc

FL_OPTI = 
#-O3 -flto
FLAGS = -Wall -Wextra $(FL_OPTI)
LFLAGS = $(FLAGS)
CFLAGS = -c $(FLAGS)

LIB = libft/libft.a

HEADERS = include/ft_malloc.h libft/include/libft.h 
CINCLUDE = -I include -I libft/include

NAME = test

SRC_FILES = 	\
main_test.c		\
ft_malloc.c		\
malloc_data.c	\
malloc_tiny.c	\
malloc_small.c	\
malloc_large.c	\
ft_free.c		\
ft_free_tiny.c	\
ft_free_small.c	\
ft_free_large.c	\
ft_realloc.c	\
show_alloc_mem.c\


SRC_DIR = src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ_DIR = obj/
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@echo "$(GREEN)objects done sir !$(RESET)"
	@$(CC) $(LFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled sir !$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CINCLUDE) $(CFLAGS) -o $@ $<
	@echo -n '.'

$(LIB) :
	@make -C libft

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@#echo "$(GREEN)Object directory created sir !$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects deleted sir !$(RESET)"
	@rm -rf $(OBJ_DIR)
	@#echo "$(RED)Object directory deleted sir !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted sir !$(RESET)"

lclean: fclean
	@make -C libft fclean
	@echo "$(RED)libft deleted sir !$(RESET)"

re: fclean all

lre: lclean all