# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/09 11:58:48 by qgilbert          #+#    #+#              #
#    Updated: 2019/06/09 11:58:50 by qgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = ./source/

OBJDIR = ./objects/

SRC = one.c ft_itoa_ll.c ft_int_base.c flag_check.c \
	print_str.c print_num.c format_check.c print_d.c \
	print_c_u.c print_o_x.c print_f.c str_format.c

OBJS = $(addprefix $(OBJDIR), $(SRC:.c=.o))

HEAD = ./head

LIBFT = ./libft

LIBFT_I = ./libft/libft.a

GCC_FLAGS = gcc  -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(GCC_FLAGS) -I $(HEAD) -o $@ -c $<

$(NAME):$(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT_I) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJDIR) 
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
