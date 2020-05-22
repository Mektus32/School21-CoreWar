/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_char_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:40:34 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/13 21:41:32 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void			all_arg(t_assm *assm, t_info *info, t_arg *arg)
{
	int	delta;

	delta = 0;
	if (arg->lable != NULL)
		search_lbl(assm, info, arg);
	if (arg->bl_ind != 0)
		delta += write_to_buffer(assm, &arg->ind, IND_SIZE);
	if (arg->bl_dir != 0)
		delta += write_to_buffer(assm, &arg->dir, info->size_dir);
	if (arg->bl_reg != 0)
		delta += write_to_buffer(assm, &arg->reg, 1);
	assm->pos_glob += delta;
	info->oct_start += delta;
}

char			*read_arguments(t_assm *assm, t_arg *arg, char *start)
{
	while (*start)
	{
		if (ft_isdigit(*start) || *start == ':' || *start == '-')
			start = read_ind_adg(arg, start);
		if (*start == '%')
			start = read_dir_adg(arg, start, assm);
		if (*start == 'r')
			start = read_reg_adg(assm, arg, start + 1);
		if (ft_isalpha(*start))
			error("Error argument.", assm);
		if (*start == ',')
			return (start);
		if (*start == COMMENT_CHAR || *start == ALT_COMMENT_CHAR)
		{
			while (*start)
				start++;
			return (start);
		}
		if (*start == '\0')
			continue ;
		start++;
	}
	return (start);
}

t_opr			*get_arg_opr(t_assm *assm, char *start)
{
	t_opr *opr;

	if (!(opr = (t_opr *)malloc(sizeof(t_opr))))
		sys_error(assm, "Error malloc\n");
	init_opt(opr);
	start = read_arguments(assm, &opr->args[0], start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->args[1], start);
	if (*start == ',')
	{
		start++;
		opr->count_args++;
	}
	start = read_arguments(assm, &opr->args[2], start);
	while (ft_isspace(*start))
		start++;
	if (*start != '\0' && *start != COMMENT_CHAR && *start != ALT_COMMENT_CHAR)
		error("Error argument.", assm);
	return (opr);
}

unsigned char	get_code_arg(t_opr *opr)
{
	unsigned char code;

	code = opr->args[0].bl_ind | opr->args[0].bl_dir | opr->args[0].bl_reg;
	code = code << 2;
	code = code | opr->args[1].bl_ind | opr->args[1].bl_dir |
			opr->args[1].bl_reg;
	code = code << 2;
	code = code | opr->args[2].bl_ind | opr->args[2].bl_dir |
			opr->args[2].bl_reg;
	code = code << 2;
	return (code);
}
