/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:21:20 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/13 22:11:03 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		main(int ac, char **av)
{
	t_assm	assm;

	init(&assm);
	if (ac != 2)
		sys_error(&assm, "Usage: ./asm namefile.s\n");
	open_file_s(&assm, av[1]);
	assm.fd_cor = 0;
	read_name_comment(&assm);
	read_instruction(&assm);
	create_file_cor(&assm, av[1]);
	write_header(&assm);
	write(assm.fd_cor, assm.buffer, assm.buffer_pos);
	write_exec_code_size(&assm);
	write_lables(&assm);
	free_memory(&assm);
	close_files(&assm);
	return (0);
}

void	init_arg(t_arg *arg)
{
	arg->dir = 0;
	arg->ind = 0;
	arg->reg = 0;
	arg->lable = NULL;
	arg->code_ind = 0;
	arg->code_dir = 0;
	arg->code_reg = 0;
}

void	init(t_assm *assm)
{
	assm->counter_line = 0;
	assm->pos_glob = LEN_HEAD;
	assm->lbl = NULL;
	assm->line = NULL;
	assm->name_cor = NULL;
	assm->buffer = NULL;
	ft_memset(assm->head.prog_name, 0x00, PROG_NAME_LENGTH);
	ft_memset(assm->head.comment, 0x00, COMMENT_LENGTH);
	if ((assm->buffer =
			(unsigned char*)ft_memalloc(sizeof(unsigned char) * 682)) == NULL)
		sys_error(assm, "Memory not allocated.\n");
	assm->buffer_size = 682;
	assm->buffer_pos = 0;
}

void	init_opt(t_opr *opr)
{
	init_arg(&opr->args[0]);
	init_arg(&opr->args[1]);
	init_arg(&opr->args[2]);
	opr->count_args = 1;
	opr->info.size_dir = 0;
	opr->info.code_args = 0;
	opr->info.oct_start = 0;
}
