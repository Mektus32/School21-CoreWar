/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live_zjmp_fork_fork_add_sub_aff_and_or          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:01:04 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:01:31 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

void	op_live(t_diasm *diasm)
{
	unsigned int	dir;
	char			*str_num;

	ft_putstr_fd("\tlive %", diasm->fd_s);
	dir = read_four_byte(diasm);
	str_num = ft_itoa((int)dir);
	ft_putendl_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
}

void	op_zjmp_fork_lfork(t_diasm *diasm, const char *op_name)
{
	unsigned short	dir;
	char			*str_num;

	ft_putstr_fd(op_name, diasm->fd_s);
	dir = read_two_byte(diasm);
	str_num = ft_itoa((short)dir);
	ft_putendl_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
}

void	op_add_sub(t_diasm *diasm, char *op_name)
{
	unsigned char code_arg;

	code_arg = read_one_byte(diasm);
	ft_putstr_fd(op_name, diasm->fd_s);
	if (code_arg == 0x54)
	{
		write_registr(diasm, 1);
		write_registr(diasm, 1);
		write_registr(diasm, 0);
	}
}

void	op_aff(t_diasm *diasm)
{
	unsigned char code_arg;

	ft_putstr_fd("\taff ", diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if (code_arg == 0x40)
		write_registr(diasm, 0);
}

void	op_and_or_xor(t_diasm *diasm, char *op_name)
{
	unsigned char code_arg;

	ft_putstr_fd(op_name, diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if ((code_arg & FIR_ARG) == 0x40)
		write_registr(diasm, 1);
	else if ((code_arg & FIR_ARG) == 0x80)
		write_direct(diasm, 1);
	else if ((code_arg & FIR_ARG) == 0xc0)
		write_indirect(diasm, 1);
	if ((code_arg & SEC_ARG) == 0x10)
		write_registr(diasm, 1);
	else if ((code_arg & SEC_ARG) == 0x20)
		write_direct(diasm, 1);
	else if ((code_arg & SEC_ARG) == 0x30)
		write_indirect(diasm, 1);
	if ((code_arg & THI_ARG) == 0x04)
		write_registr(diasm, 0);
}
