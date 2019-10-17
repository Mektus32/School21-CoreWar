/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:53:11 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:30:43 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_format_check_big(const char *format, t_print *pr)
{
	if (!ft_strncmp(format, "D", 1))
	{
		(*pr).format = 2;
		(*pr).mod = 5;
	}
	else if (!ft_strncmp(format, "O", 1))
	{
		(*pr).format = 5;
		(*pr).mod = 5;
	}
	else if (!ft_strncmp(format, "U", 1))
	{
		(*pr).format = 11;
		(*pr).mod = 5;
	}
	else if (ft_strncmp(format, "X", 1) == 0)
		(*pr).format = 8;
	else if (ft_strncmp(format, "p", 1) == 0)
	{
		(*pr).rr = 1;
		(*pr).format = 9;
	}
	else
		(*pr).net = 1;
}

const char	*ft_format_check(const char *format, t_print *pr)
{
	if (ft_strncmp(format, "s", 1) == 0 || ft_strncmp(format, "S", 1) == 0)
		(*pr).format = 1;
	else if (ft_strncmp(format, "d", 1) == 0)
		(*pr).format = 2;
	else if (ft_strncmp(format, "c", 1) == 0 || ft_strncmp(format, "C", 1) == 0)
		(*pr).format = 3;
	else if (ft_strncmp(format, "i", 1) == 0)
		(*pr).format = 4;
	else if (ft_strncmp(format, "o", 1) == 0)
		(*pr).format = 5;
	else if (ft_strncmp(format, "u", 1) == 0)
		(*pr).format = 6;
	else if (ft_strncmp(format, "x", 1) == 0)
		(*pr).format = 7;
	else if (!ft_strncmp(format, "f", 1) || !ft_strncmp(format, "F", 1))
		(*pr).format = 10;
	else if (!ft_strncmp(format, "b", 1))
		(*pr).format = 12;
	else
		ft_format_check_big(format, pr);
	if (((*pr).format >= 7 && (*pr).format <= 9) || (*pr).format == 5)
		(*pr).pr_x = 1;
	if ((*pr).format != 0)
		format++;
	return (format);
}
