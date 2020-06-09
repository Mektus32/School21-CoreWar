/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 08:13:14 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/13 20:41:23 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/head/libftprintf.h"
# include "op.h"
# include <fcntl.h>

# define C_REG		0x1
# define C_DIR		0x2
# define C_IND		0x3

# define LEN_HEAD	(4+PROG_NAME_LENGTH+4+COMMENT_LENGTH+4+4)

typedef struct		s_assm
{
	char			*line;
	int				fd_cor;
	int				fd_s;
	char			*name_cor;
	size_t			pos_glob;
	size_t			counter_line;
	t_header_s		head;
	struct s_lbl	*lbl;
	unsigned char	*buffer;
	int				buffer_size;
	int				buffer_pos;
}					t_assm;

typedef struct		s_lbl
{
	char			*name;
	int				bl;
	size_t			position;
	struct s_lbl	*next;
	struct s_gab	*gab;
}					t_lbl;

typedef struct		s_gab
{
	size_t			pos_write;
	short			oct_count;
	short			oct_start;
	struct s_gab	*next;
}					t_gab;

typedef struct		s_arg
{
	int				dir;
	short			ind;
	char			reg;
	char			*lable;
	unsigned char	bl_dir;
	unsigned char	bl_ind;
	unsigned char	bl_reg;
}					t_arg;

typedef struct		s_info
{
	short			size_dir;
	short			bl_code_arg;
	short			oct_start;
}					t_info;

typedef struct		s_opr
{
	t_arg			args[3];
	short			count_args;
	struct s_info	info;
}					t_opr;

/*
** File file.c
*/
int					check_name(char *name);
char				*dot_cor(char *name);
void				open_file_s(t_assm *assm, char *name);
void				close_files(t_assm *assm);
void				create_file_cor(t_assm *assm, char *name);
/*
** File write.c
*/
void				write_header(t_assm *assm);
int					write_to_buffer(t_assm *assm, void *bits, int len_bits);
int					write_to_file(t_assm *assm, int fd,
							void *bits, int len_bits);
void				write_char_to_buffer(t_assm *assm, unsigned char chr);
/*
** File write_labels.c
*/
int					get_position(size_t position, t_gab *gab);
void				write_in_position(t_lbl *lbl, t_assm *assm);
void				write_lables(t_assm *assm);
void				write_exec_code_size(t_assm *assm);
/*
** File read_comment_champion.c
*/
void				read_name_champion(char *line, t_assm *assm);
void				working_name(char *line, t_assm *assm);
void				read_comment_champion(char *line, t_assm *assm);
/*
** File read_name_comment.c
*/
void				working_comment(char *line, t_assm *assm);
int					working_dot(t_assm *assm, char *line,
						int *name, int *comment);
int					search_char(t_assm *assm, int *name, int *comment);
void				read_name_comment(t_assm *assm);
/*
** File instruction.c
*/
void				working_instruction(t_assm *assm, char *line);
void				read_instruction(t_assm *assm);
void				working_operation(t_assm *assm, char *start, char *line);
void				instruction(t_assm *assm, char *line);
int					isprint_char(int c);
/*
** File arguments.c
*/
void				all_arg(t_assm *assm, t_info *info, t_arg *arg);
char				*read_arguments(t_assm *assm, t_arg *arg, char *start);
t_opr				*get_arg_opr(t_assm *assm, char *start);
unsigned char		get_code_arg(t_opr *opr);
/*
** File lable_add_list.c
*/
int					islablechar(char c);
void				check_lable(t_assm *assm, char *start, char *line);
t_lbl				*create_lable(t_assm *assm, char *start, char *end);
int					search_dub_lable(t_assm *assm, t_lbl *lbl, char *start,
		char *line);
void				add_lable_list(t_assm *assm, char *start, char *line);
/*
** File arguments_get.c
*/
char				*create_lable_arg(char *start, t_arg *arg);
char				*read_ind_adg(t_arg *arg, char *start);
char				*read_reg_adg(t_assm *assm, t_arg *arg, char *start);
char				*read_dir_adg(t_arg *arg, char *start, t_assm *assm);
/*
** File arguments_check_two.c
*/
void				check_op_ld_lld_arg(t_assm *assm, t_opr *opr);
void				check_op_st_arg(t_assm *assm, t_opr *opr);
void				check_op_or_xor_and_arg(t_assm *assm, t_opr *opr);
/*
** File arguments_check_one.c
*/
void				check_op_ldi_lldi_arg(t_assm *assm, t_opr *opr);
void				check_op_fork_lfork_zjmp_live_arg(t_assm *assm, t_opr *opr);
void				check_op_aff_arg(t_assm *assm, t_opr *opr);
void				check_op_add_sub_arg(t_assm *assm, t_opr *opr);
void				check_op_sti_arg(t_assm *assm, t_opr *opr);
/*
** File label.c
*/
t_lbl				*get_lbl(t_assm *assm, t_lbl **lbl, char *lable);
t_gab				*new_gab(t_assm *assm, t_info **info, t_arg *arg);
void				search_lbl(t_assm *assm, t_info *info, t_arg *arg);
void				working_lable(t_assm *assm, char *start, char *line);
/*
** File operations.c
*/
void				five_char_operator(t_assm *assm, char *start);
void				three_char_operator(t_assm *assm, char *start);
void				op_all(t_assm *assm, t_opr *opr, int code,
						void (*func)(t_assm*, t_opr*));
void				two_char_operator(t_assm *assm, char *start);
void				four_char_operator(t_assm *assm, char *start);
/*
** File error_and_clean_memory.c.c
*/
void				sys_error(t_assm *assm, char *err);
void				delete_list_gab(t_gab *gab);
void				free_memory(t_assm *assm);
void				error(const char *msg, t_assm *assm);
void				delete_opr(t_opr **opr);
/*
** File main.c
*/
int					main(int ac, char **av);
void				init(t_assm *assm);
void				init_arg(t_arg *arg);
void				init_opt(t_opr *opr);
#endif
