/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:58:19 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 13:41:31 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*create_lable_arg(char *start, t_arg *arg)
{
	char *temp;

	temp = start;
	while (islablechar(*start) && *start != '\0')
		start++;
	arg->lable = ft_strnew(start - temp);
	ft_strncpy(arg->lable, temp, start - temp);
	return (start);
}

char	*read_ind_adg(t_arg *arg, char *start)
{
	arg->code_ind = C_IND;
	if (*start == ':')
	{
		start = create_lable_arg((start + 1), arg);
		return (start);
	}
	arg->ind = ft_atoi(start);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	return (start);
}

char	*read_reg_adg(t_assm *assm, t_arg *arg, char *start)
{
	if (!ft_isdigit(*start))
		error("Error registr.", assm);
	arg->code_reg = C_REG;
	arg->reg = ft_atoi(start);
	if (arg->reg <= 0)
		error("Error number registr.", assm);
	while (ft_isdigit(*start))
		start++;
	return (start);
}

char	*read_dir_adg(t_arg *arg, char *start, t_assm *assm)
{
	start++;
	arg->code_dir = C_DIR;
	if (ft_isdigit(*start) || *start == '-')
		arg->dir = ft_atoi(start);
	else if (*start == ':')
		start = create_lable_arg(start + 1, arg);
	else
		error("Lexical error at.", assm);
	while (ft_isdigit(*start) || *start == '-')
		start++;
	return (start);
}
