NAME = diasm

FILEC =	main.c\
		op_live_zjmp_fork_fork_add_sub_aff_and_or_xor.c\
		op_ls_lld_st_sti_ldi_lldi.c\
		print_bit_hex.c\
		read_byts.c\
		write_name_comment.c\
		write_to_file.c

DIRSRC = ./source/
FLAGS = -Wall -Wextra -Werror

OBJ = $(FILEC:.c=.o)

SRC = $(addprefix $(DIRSRC), $(FILEC))

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) $(HFILES) -c $(SRC)
	gcc $(FLAGS) $(OBJ) -L ./libft -lftprintf -o $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)
	
re: fclean all
	make re -C ./libft
