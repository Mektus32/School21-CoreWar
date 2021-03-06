/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lable_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 08:17:37 by pdonnie           #+#    #+#             */
/*   Updated: 2019/03/13 20:29:17 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		islablechar(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 95)
		return (1);
	return (0);
}

void	check_lable(t_assm *assm, char *start, char *line)
{
	while (start < line)
	{
		if (!islablechar(*start))
			error("Error lable char.", assm);
		start++;
	}
}

t_lbl	*create_lable(t_assm *assm, char *start, char *end)
{
	t_lbl	*new;
	int		len;

	len = end - start;
	if (!(new = (t_lbl*)malloc(sizeof(t_lbl))))
		sys_error(assm, "Eror malloc\n");
	if (!(new->name = ft_strnew(len)))
		sys_error(assm, "Eror malloc\n");
	ft_strncpy(new->name, start, len);
	new->next = NULL;
	new->check = 0;
	new->gab = NULL;
	return (new);
}

int		search_dub_lable(t_assm *assm, t_lbl *lbl, char *start, char *line)
{
	int		len;
	int		len_str;
	int		diff;

	diff = line - start;
	while (lbl)
	{
		len = ft_strlen(lbl->name);
		len_str = (len > diff ? len : diff);
		if (!(ft_strncmp(start, lbl->name, len_str)))
		{
			if (lbl->check == 0)
			{
				lbl->position = assm->pos_glob;
				lbl->check = 1;
			}
			return (1);
		}
		lbl = lbl->next;
	}
	return (0);
}

void	add_lable_list(t_assm *assm, char *start, char *line)
{
	t_lbl *lbl;

	if (!assm->lbl)
	{
		assm->lbl = create_lable(assm, start, line);
		assm->lbl->check = 1;
		assm->lbl->position = assm->pos_glob;
		return ;
	}
	if (search_dub_lable(assm, assm->lbl, start, line))
		return ;
	lbl = create_lable(assm, start, line);
	lbl->next = assm->lbl;
	assm->lbl = lbl;
	assm->lbl->check = 1;
	assm->lbl->position = assm->pos_glob;
}
