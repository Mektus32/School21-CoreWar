/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:43:01 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 21:02:56 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_position(size_t position, t_gab *gab)
{
	int	num;

	num = position - gab->pos_write + gab->oct_start;
	return (num);
}

void	write_in_position(t_lbl *lbl, t_assm *assm)
{
	t_gab	*gab;
	int		b;

	gab = lbl->gab;
	while (gab)
	{
		if (lseek(assm->fd_cor, gab->pos_write, SEEK_SET) == -1L)
			sys_error(assm, "Seek Error\n");
		b = get_position(lbl->position, gab);
		write_to_file(assm, assm->fd_cor, &b, gab->oct_count);
		gab = gab->next;
	}
}

void	write_lables(t_assm *assm)
{
	t_lbl *lbl;

	lbl = assm->lbl;
	while (lbl)
	{
		if (lbl->bl == 0)
			sys_error(assm, "Not lable Error\n");
		write_in_position(lbl, assm);
		lbl = lbl->next;
	}
}

void	write_exec_code_size(t_assm *assm)
{
	size_t bot_size;

	bot_size = assm->pos_glob - LEN_HEAD;
	if (lseek(assm->fd_cor, 8 + PROG_NAME_LENGTH, SEEK_SET) == -1L)
		sys_error(assm, "Seek Error\n");
	write_to_file(assm, assm->fd_cor, &bot_size, 4);
}
