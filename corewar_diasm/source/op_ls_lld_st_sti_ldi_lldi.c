/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ls_lld_st_sti_ldi_lldi.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:01:36 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:01:54 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

void	op_ls_lld(t_diasm *diasm, char *op_name)
{
	unsigned char code_arg;

	ft_putstr_fd(op_name, diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if ((code_arg & FIR_ARG) == 0x80)
		write_direct(diasm, 1);
	else if ((code_arg & FIR_ARG) == 0xc0)
		write_indirect(diasm, 1);
	if ((code_arg & SEC_ARG) == 0x10)
		write_registr(diasm, 0);
}

void	op_st(t_diasm *diasm)
{
	unsigned char code_arg;

	ft_putstr_fd("\tst ", diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if ((code_arg & FIR_ARG) == 0x40)
		write_registr(diasm, 1);
	if ((code_arg & SEC_ARG) == 0x10)
		write_registr(diasm, 0);
	else if ((code_arg & SEC_ARG) == 0x30)
		write_indirect(diasm, 0);
}

void	op_sti(t_diasm *diasm)
{
	unsigned char code_arg;

	ft_putstr_fd("\tsti ", diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if ((code_arg & FIR_ARG) == 0x40)
		write_registr(diasm, 1);
	if ((code_arg & SEC_ARG) == 0x10)
		write_registr(diasm, 1);
	else if ((code_arg & SEC_ARG) == 0x20)
		write_direct_two_byte(diasm, 1);
	else if ((code_arg & SEC_ARG) == 0x30)
		write_indirect(diasm, 1);
	if ((code_arg & THI_ARG) == 0x04)
		write_registr(diasm, 0);
	else if ((code_arg & THI_ARG) == 0x08)
		write_direct_two_byte(diasm, 0);
}

void	op_ldi_lldi(t_diasm *diasm, char *op_name)
{
	unsigned char code_arg;

	ft_putstr_fd(op_name, diasm->fd_s);
	code_arg = read_one_byte(diasm);
	if ((code_arg & FIR_ARG) == 0x40)
		write_registr(diasm, 1);
	else if ((code_arg & FIR_ARG) == 0x80)
		write_direct_two_byte(diasm, 1);
	else if ((code_arg & FIR_ARG) == 0xc0)
		write_indirect(diasm, 1);
	if ((code_arg & SEC_ARG) == 0x10)
		write_registr(diasm, 1);
	else if ((code_arg & SEC_ARG) == 0x20)
		write_direct_two_byte(diasm, 1);
	if ((code_arg & THI_ARG) == 0x04)
		write_registr(diasm, 0);
}
