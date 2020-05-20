# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 19:44:17 by qgilbert          #+#    #+#              #
#    Updated: 2020/02/03 17:29:08 by qgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, obj, asm

NAME = corewar
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
SOURCES_PATH = ./src_cor/
OBJECTS_PATH = ./objects/
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDE = includes/corewar.h includes/op.h
INCLUDES = -I ./includes

SOURCES_NAME =	main.c \
            		arg.c \
            		carr_list.c \
            		ft_add.c \
            		ft_zjmp.c \
            		ft_ld.c \
            		ft_ldi.c \
            		ft_live.c \
            		ft_st.c \
            		go_cor.c \
            		ft_sti.c \
            		ft_aff.c \
            		ft_and.c \
            		ft_fork_lfork.c \
            		ft_or_xor.c \
            		ft_sub.c \
            		print_code.c \
            		ft_liba.c \
            		read_byte.c \
            		arena.c \
            		champ.c \
            		parse_av.c \
            		do_op.c \
            		visu_init.c \
            		visu_cicle.c \
            		write_map.c
SOURCES = $(addprefix $(SOURCES_PATH), $(SOURCES_NAME))
OBJECTS_NAME = $(SOURCES_NAME:%.c=%.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_NAME))
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# asm
ASM = ./corewar_asm

all : $(NAME) asm

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -lncurses $(LIBFT) $(PRINTF) -o $@ $(OBJECTS)

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)

FORCE:

$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c $(INCLUDE)
	@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

asm:
	@make -C $(ASM)

clean :
		@/bin/rm -f $(OBJECTS)
	    @/bin/rm -rf $(OBJECTS_PATH)
	    @/bin/rm -f *.h.gch
	    @/bin/rm -f .*.swp
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(PRINTF_DIR)
		@make -C $(ASM) clean

fclean : clean
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(PRINTF_DIR)
		@/bin/rm -f $(NAME)
		@make -C $(ASM) fclean

re : fclean all
