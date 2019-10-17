# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/02 16:02:21 by ojessi            #+#    #+#              #
#    Updated: 2019/06/11 13:37:56 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_args.c \
	  choise_spec.c \
	  ft_atoi.c \
	  ft_free_strjoin_duo.c \
	  ft_free_strjoin_rev.c \
	  ft_free_strncpy.c \
	  ft_ftoa.c \
	  ft_itoa.c \
	  ft_ltoa_base.c \
	  ft_ltoa.c \
	  ft_memset.c \
	  ft_printf.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strnew.c \
	  ft_strtolower.c \
	  ft_ultoa_base.c \
	  ft_ultoa.c \
	  init_arg.c \
	  print_digit.c \
	  print_double.c \
	  print_non_printabl.c \
	  print_spec_etc.c \
	  print_spec.c \
	  print_xox.c \
	  settings.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: all clean fclean re, obj, red, grn, off
.SUFFIXES: .c .o

all: obj grn $(NAME) off

red:
	@echo "\x1B[31m"
	
grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@

clean: red
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
