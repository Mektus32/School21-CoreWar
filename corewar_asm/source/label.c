/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_lbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:51:36 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/14 15:21:17 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "stdlib.h"

t_lbl	*get_lbl(t_assm *assm, t_lbl **lbl, char *lable)
{
	t_lbl *temp;

	temp = *lbl;
	while (temp)
	{
		if (!ft_strcmp(temp->name, lable))
			return (temp);
		temp = temp->next;
	}
	temp = create_lable(assm, lable, lable + ft_strlen(lable));
	temp->next = *lbl;
	*lbl = temp;
	(*lbl)->check = 0;
	(*lbl)->position = LEN_HEAD;
	return (temp);
}

t_gab	*new_gab(t_assm *assm, t_info **info, t_arg *arg)
{
	t_gab *new;

	if (!(new = (t_gab *)malloc(sizeof(t_gab))))
		sys_error(assm, "Error malloc.\n");
	if (arg->code_dir != 0)
	{
		new->oct_start = ((*info)->code_args == 1 ? (*info)->oct_start : 1);
		new->oct_count = (*info)->size_dir;
	}
	else if (arg->code_ind != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 2;
	}
	else if (arg->code_reg != 0)
	{
		new->oct_start = (*info)->oct_start;
		new->oct_count = 1;
	}
	new->pos_write = assm->pos_glob;
	new->next = NULL;
	return (new);
}

void	search_lbl(t_assm *assm, t_info *info, t_arg *arg)
{
	t_gab *gab;
	t_lbl *lbl;

	gab = new_gab(assm, &info, arg);
	lbl = get_lbl(assm, &assm->lbl, arg->lable);
	if (lbl->gab == NULL)
		lbl->gab = gab;
	else
	{
		gab->next = lbl->gab;
		lbl->gab = gab;
	}
}

void	parse_lable(t_assm *assm, char *start, char *line)
{
	check_lable(assm, start, line);
	add_lable_list(assm, start, line);
	parse_instruction(assm, line + 1);
}
