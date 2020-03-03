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

.PHONY: all, clean, fclean, re, obj, red, grn, off, asm, diasm

NAME = corewar

# src / obj files
SRC =	main.c \
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




OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g

# ft library
FT = ./libft
FT_LIB = $(addprefix $(FT), libft.a)
FT_INC = -I ./libft
FT_LNK = ./libft/libft.a

# printf library
PR = ./ft_printf
PR_LIB = $(addprefix $(PR), libftprintf.a)
PR_INC = -I ./ft_printf
PR_LNK = ./ft_printf/libftprintf.a


# directories
#SRCDIR = ./src_cor/
#SRCDIR = ./src_cor_arina/
SRCDIR = ./src_cor/

INCDIR = -I ./includes/
OBJDIR = ./obj/

# asm
ASM = ./corewar_asm

# diasm
DIASM = ./corewar_diasm

all: $(NAME)

$(NAME): obj $(FT_LIB) $(PR_LIB) grn $(OBJ) asm diasm
	@$(CC) $(CFLAGS) $(OBJ) -lncurses $(PR_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "\x1b[0m"

red:
	@echo "\x1B[31m"

grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

obj:
	@mkdir -p $(OBJDIR)

$(FT_LIB):
	@make -C $(FT)

$(PR_LIB):
	@make -C $(PR)

asm:
	@make -C $(ASM)

diasm:
	@make -C $(DIASM)


$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(PR_INC) $(FT_INC) $(INCDIR) -o $@ -c $<

clean: red
	/bin/rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(PR) clean
	@make -C $(ASM) clean
	@make -C $(DIASM) clean


fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(FT) fclean
	make -C $(PR) fclean
	make -C $(ASM) fclean
	make -C $(DIASM) fclean

re: fclean all