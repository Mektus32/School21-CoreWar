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
					arguments.c\
             		arguments_check_one.c\
             		arguments_check_two.c\
             		arguments_get.c\
             		error_and_clean_memory.c\
             		file.c\
             		init_agr.c\
             		lable_add_list.c\
             		label.c\
             		operations.c\
             		read_comment_champ.c\
             		read_name_comment.c\
             		write.c\
             		write_labels.c
SOURCES = $(addprefix $(SOURCES_PATH), $(SOURCES_NAME))
OBJECTS_NAME = $(SOURCES_NAME:%.c=%.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_NAME))

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(PRINTF) -o $@ $(OBJECTS)

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

$(PRINTF): FORCE
	@make -C $(PRINTF_DIR)

FORCE:

$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c $(INCLUDE)
	@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

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
