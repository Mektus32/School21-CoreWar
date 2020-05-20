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
INCLUDES = ./includes/corewar.h ./includes/op.h
OBJDIR = ./obj/

# asm
ASM = ./corewar_asm

all: $(NAME) asm

$(NAME): $(FT_LIB) $(PR_LIB) grn $(OBJ)
	$(CC) $(CFLAGS) -lncurses $(PR_LNK) $(FT_LNK) -lm -o $@ $(OBJ)
	@echo "\x1b[0m"

red:
	@echo "\x1B[31m"

grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

$(FT_LIB): FORCE
	@make -C $(FT)

$(PR_LIB): FORCE
	@make -C $(PR)

FORCE:

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(PR_INC) $(FT_INC) $(INCDIR) -c $< -o $@

asm:
	@make -C $(ASM)

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(PR) clean
	@make -C $(ASM) clean


fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(FT) fclean
	@make -C $(PR) fclean
	@make -C $(ASM) fclean

re: fclean all
