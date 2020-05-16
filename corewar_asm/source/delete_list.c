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

void	sys_err_rm(t_assm *assm, char *err)
{
	write(2, err, ft_strlen(err));
	remove(assm->name_cor);
	exit(0);
}

void	working_instruction(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
			return ;
		if (isprint_char(*line))
		{
			instruction(assm, line);
			return ;
		}
		line++;
	}
}

void	read_instruction(t_assm *assm)
{
	char	*line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		working_instruction(assm, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

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

void	delete_list(t_assm *assm)
{
	t_lbl *lbl;

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
