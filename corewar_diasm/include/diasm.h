/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diasm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:06:35 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:08:22 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIASM_H
# define DIASM_H

# include "../libft/libft.h"
# include "op.h"

# define FIR_ARG 0xc0
# define SEC_ARG 0x30
# define THI_ARG 0xc

typedef struct	s_diasm
{
	char		*name_cor;
	char		*name_s;
	int			fd_cor;
	int			fd_s;
}				t_diasm;
/*
** File print_bit_hex.c
*/
void			init(t_diasm *diasm);
void			open_file_cor(t_diasm *diasm, char *name);
char			*dot_s(char *name);
void			create_file_s(t_diasm *diasm);
void			printf_bit_hex(unsigned char *arr);
/*
** File write_name_comment.c
*/
void			check_exec_magic(char *buf);
void			write_name(t_diasm *diasm);
void			write_comment(t_diasm *diasm);
void			write_name_comment(t_diasm *diasm);
/*
** File read_byts.c
*/
unsigned int	move_to_uint(unsigned char *buf);
unsigned short	move_to_ushort(unsigned char *buf);
unsigned char	read_one_byte(t_diasm *diasm);
unsigned int	read_four_byte(t_diasm *diasm);
unsigned short	read_two_byte(t_diasm *diasm);
/*
** File write_to_file.c
*/
void			write_registr(t_diasm *diasm, int flag);
void			write_direct(t_diasm *diasm, int flag);
void			write_direct_two_byte(t_diasm *diasm, int flag);
void			write_indirect(t_diasm *diasm, int flag);
/*
** File op_live_zjmp_fork_fork_add_sub_aff_and_or_xor.c
*/
void			op_live(t_diasm *diasm);
void			op_zjmp_fork_lfork(t_diasm *diasm, const char *op_name);
void			op_add_sub(t_diasm *diasm, char *op_name);
void			op_aff(t_diasm *diasm);
void			op_and_or_xor(t_diasm *diasm, char *op_name);
/*
** File op_ls_lld_st_sti_ldi_lldi.c
*/
void			op_ls_lld(t_diasm *diasm, char *op_name);
void			op_st(t_diasm *diasm);
void			op_sti(t_diasm *diasm);
void			op_ldi_lldi(t_diasm *diasm, char *op_name);
/*
** File main.c
*/
void			woking_operation_09_0f(t_diasm *diasm, unsigned char op);
void			woking_operation_01_08(t_diasm *diasm, unsigned char op);
void			write_instruction(t_diasm *diasm);
void			close_file(t_diasm *diasm);
int				main(int ac, char **av);
#endif
