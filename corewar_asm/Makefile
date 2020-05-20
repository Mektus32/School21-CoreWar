# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:12:39 by pdonnie           #+#    #+#              #
#    Updated: 2019/12/15 07:52:24 by pdonnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc
FLAGS = -Wall -Werror -Wextra
SOURCES_PATH = ./source/
OBJECTS_PATH = ./objects/
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDE = include/asm.h include/op.h
INCLUDES = -I ./libft/includes/libft.h -I ./printf/head/printf.h -I ./include/asm.h -I ./include/op.h

SOURCES_NAME =	main.c\
             		add_lable_list.c\
             		check_op_or_xor_and_arg.c\
             		check_op_st_arg.c\
             		delete_list.c\
             		four_char_operator.c\
             		init_agr.c\
             		isprint_char.c\
             		read_comment_champ.c\
             		read_dir_arg.c\
             		read_name_comment.c\
             		search_lbl.c\
             		write_header.c
SOURCES = $(addprefix $(SOURCES_PATH), $(SOURCES_NAME))
OBJECTS_NAME = $(SOURCES_NAME:%.c=%.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_NAME))

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDE_MLX) $(LIBFT) $(PRINTF) -o $@ $(OBJECTS)

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

FORCE:

$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c $(INCLUDE)
	@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJECTS_PATH)
	@/bin/rm -f *.h.gch
	@/bin/rm -f .*.swp
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@/bin/rm -f $(NAME)

re : fclean all
