/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 08:13:50 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 19:35:56 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	delete_list_gab(t_gab *gab)
{
	t_gab *temp;

	temp = gab;
	while (gab)
	{
		gab = gab->next;
		free(temp);
		temp = gab;
	}
}

void	free_memory(t_assm *assm)
{
	t_lbl *lbl;

	if (assm->line)
		ft_strdel(&(assm->line));
	if (assm->name_cor)
		ft_strdel(&(assm->line));
	if (assm->buffer)
		free(assm->buffer);
	lbl = assm->lbl;
	while (assm->lbl)
	{
		assm->lbl = assm->lbl->next;
		ft_strdel(&lbl->name);
		delete_list_gab(lbl->gab);
		free(lbl);
		lbl = assm->lbl;
	}
	assm->lbl = NULL;
}

void	sys_error(t_assm *assm, char *err)
{
	write(2, err, ft_strlen(err));
	free_memory(assm);
	exit(0);
}

void	error(const char *msg, t_assm *assm)
{
	ft_printf("%s Line [%d].\n", msg, assm->counter_line);
	free_memory(assm);
	exit(0);
}

void	delete_opr(t_opr **opr)
{
	ft_strdel(&(*opr)->args[0].lable);
	ft_strdel(&(*opr)->args[1].lable);
	ft_strdel(&(*opr)->args[2].lable);
	free(*opr);
}
