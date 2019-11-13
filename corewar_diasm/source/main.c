/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:58:59 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 18:48:01 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

void	woking_operation_09_0f(t_diasm *diasm, unsigned char op)
{
	if (op == 0x09)
		op_zjmp_fork_lfork(diasm, "\tzjmp %");
	else if (op == 0x10)
		op_aff(diasm);
	else if (op == 0x0a)
		op_ldi_lldi(diasm, "\tldi ");
	else if (op == 0x0b)
		op_sti(diasm);
	else if (op == 0x0c)
		op_zjmp_fork_lfork(diasm, "\tfork %");
	else if (op == 0x0d)
		op_ls_lld(diasm, "\tlld ");
	else if (op == 0x0e)
		op_ldi_lldi(diasm, "\tlidi ");
	else if (op == 0x0f)
		op_zjmp_fork_lfork(diasm, "\tlfork %");
}

void	woking_operation_01_08(t_diasm *diasm, unsigned char op)
{
	if (op == 0x01)
		op_live(diasm);
	else if (op == 0x02)
		op_ls_lld(diasm, "\tld ");
	else if (op == 0x03)
		op_st(diasm);
	else if (op == 0x04)
		op_add_sub(diasm, "\tadd ");
	else if (op == 0x05)
		op_add_sub(diasm, "\tsub ");
	else if (op == 0x06)
		op_and_or_xor(diasm, "\tand ");
	else if (op == 0x07)
		op_and_or_xor(diasm, "\tor ");
	else if (op == 0x08)
		op_and_or_xor(diasm, "\txor ");
	else
		woking_operation_09_0f(diasm, op);
}

void	write_instruction(t_diasm *diasm)
{
	int				count;
	unsigned char	op;

	count = 1;
	while (1)
	{
		if ((count = read(diasm->fd_cor, &op, 1)) == -1)
			sys_err("Error read files.\n");
		if (!count)
			break ;
		woking_operation_01_08(diasm, op);
	}
}

void	close_file(t_diasm *diasm)
{
	ft_putendl("Done!");
	ft_strdel(&diasm->name_cor);
	ft_strdel(&diasm->name_s);
	close(diasm->fd_cor);
	close(diasm->fd_s);
}

int		main(int ac, char **av)
{
	t_diasm diasm;

	if (ac != 2)
		sys_err("Error!\nUse ./asm namefile.cor\n");
	init(&diasm);
	open_file_cor(&diasm, av[1]);
	create_file_s(&diasm);
	write_name_comment(&diasm);
	write_instruction(&diasm);
	close_file(&diasm);
	return (0);
}
