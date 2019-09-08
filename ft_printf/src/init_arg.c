/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:54:40 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:54:45 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_int_arg(t_ob *ob, long *nbr)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*nbr = va_arg(ob->ap[0], long);
		return ;
	}
	*nbr = va_arg(ob->ap[0], long);
}

void	init_str_arg(t_ob *ob, char **tmp)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*tmp = va_arg(ob->ap[0], char *);
		return ;
	}
	*tmp = va_arg(ob->ap[0], char *);
}

void	init_char_arg(t_ob *ob, int *c)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*c = va_arg(ob->ap[0], int);
		return ;
	}
	*c = va_arg(ob->ap[0], int);
}

void	init_long_double_arg(t_ob *ob, long double *nbr)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*nbr = va_arg(ob->ap[0], long double);
		return ;
	}
	*nbr = va_arg(ob->ap[0], long double);
}

void	init_double_arg(t_ob *ob, double *nbr)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*nbr = va_arg(ob->ap[0], double);
		return ;
	}
	*nbr = va_arg(ob->ap[0], double);
}
