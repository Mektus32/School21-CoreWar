/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:53:51 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:32:52 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_str_format(t_print *pr, char *st_cat)
{
	int		len_z;

	len_z = 0;
	if ((*pr).space && !(*pr).plus && !(*pr).pr_x)
		ft_memset(st_cat + len_z++, ' ', 1);
	if ((*pr).rr == 1)
	{
		if (((*pr).format == 7 || (*pr).format == 9
			|| (*pr).format == 8 || (*pr).format == 5) || (*pr).format == 12)
		{
			ft_memset(st_cat + len_z++, '0', 1);
			if ((*pr).format == 7 || (*pr).format == 9)
				ft_memset(st_cat + len_z++, 'x', 1);
			else if ((*pr).format == 12)
				ft_memset(st_cat + len_z++, 'b', 1);
			else if ((*pr).format == 8)
				ft_memset(st_cat + len_z++, 'X', 1);
		}
	}
	return (len_z);
}

void		num_set(t_print *pr, t_len *len_l, char *st_cat, char *str)
{
	if ((*pr).prec_p && (*pr).prec > ((*len_l).len_str))
	{
		ft_memset(st_cat + (*len_l).len_z, '0', (*pr).prec);
		ft_memcpy(st_cat + ((*pr).prec - (*len_l).len_str + (*len_l).len_z),
		str, (*len_l).len_str);
	}
	else
		ft_memcpy(st_cat + (*len_l).len_z, str, (*len_l).len_str);
}
